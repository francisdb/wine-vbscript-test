#include <activscp.h>
#include <vbscript.h>
#include <parse.h>
#include <parser.tab.h>
#include <scriptsite.h>
#include <zlog.h>

#include "unity.h"
#include "utils.h"

// helper functions

int count_classes(parser_ctx_t ctx)
{
  int count = 0;
  const class_decl_t *classes = ctx.class_decls;
  while (classes)
  {
    count++;
    //printf("Class: %ls\n", classes->name);
    classes = classes->next;
  }
  return count;
}

void free_script_context(script_ctx_t *script_ctx)
{
  if (script_ctx) {
    free(script_ctx->site);
    free(script_ctx->global_obj);
    // free(&script_ctx->named_items);
    // free(&script_ctx->code_list);
    //free(script_ctx);
  }
}

HRESULT create_script_context(script_ctx_t *ctx)
{
    if (!ctx) return E_POINTER;

    memset(ctx, 0, sizeof(script_ctx_t));

    list_init(&ctx->named_items);
    list_init(&ctx->code_list);

    HRESULT hr = init_global(ctx);
    if (FAILED(hr)) {
        free_script_context(ctx);
        return hr;
    }

    ScriptSite *site = CreateScriptSite();
    if (!site) {
        free_script_context(ctx);
        return E_FAIL;
    }
    ctx->site = &site->IActiveScriptSite_iface;

    return S_OK;
}

// TODO we need a way to return errors from the parser
HRESULT run_expression(const WCHAR* script, VARIANT *res, DWORD flags)
{
  script_ctx_t *ctx = malloc(sizeof(script_ctx_t));
  HRESULT hr = create_script_context(ctx);
  if (FAILED(hr)) {
    return hr;
  }

  vbscode_t* code;
  hr = compile_script(ctx, script, NULL, L"", 0, 0, flags, &code);
  if (FAILED(hr)) {
    free_script_context(ctx);
    return hr;
  }

  hr = create_script_disp(ctx, &ctx->script_obj);
  if (FAILED(hr)) {
    free_script_context(ctx);
    return hr;
  }

  struct vbcaller caller = {0};
  ctx->vbcaller = &caller;

  hr = exec_global_code(ctx, code, res);
  free_script_context(ctx);
  return hr;
}

// test code below



void suiteSetUp(void)
{
  const int rc = zlog_init_from_string("[formats]\n"
  "simple = \"%-20c %-5V - %m%n\"\n"
  "[rules]\n"
  "*.INFO    >stdout;simple\n");
  if (rc) {
    printf("zlog init failed\n");
  }
}


/* sometimes you may want to get at local data in a module.
 * for example: If you plan to pass by reference, this could be useful
 * however, it should often be avoided */
//extern int Counter;

void setUp(void)
{
  /* This is run before EACH TEST */
  //Counter = 0x5a5a;
}

void tearDown(void)
{
}

void test_lexer(void)
{
  parser_ctx_t ctx = {0};
  ctx.ptr = L"10+1";
  ctx.end = ctx.ptr + wcslen(ctx.ptr);
  unsigned loc = 0;
  void *lval = malloc(sizeof(void*));

  parser_token_kind_t ret = parser_lex(lval, &loc, &ctx);
  TEST_ASSERT_EQUAL(tInt, ret);
  TEST_ASSERT_EQUAL(10L, *(LONG*)lval);
  ret = parser_lex(&lval, &loc, &ctx);
  TEST_ASSERT_EQUAL('+', ret);
  ret = parser_lex(&lval, &loc, &ctx);
  TEST_ASSERT_EQUAL(tInt, ret);
  ret = parser_lex(&lval, &loc, &ctx);
  TEST_ASSERT_EQUAL(tNL, ret);
  ret = parser_lex(&lval, &loc, &ctx);
  TEST_ASSERT_EQUAL(PARSER_EOF, ret);
}

void test_MsgBox(void)
{
  const HRESULT res = run_script(L"MsgBox \"Hello from VBScript!\"");
  TEST_ASSERT_EQUAL(0, res);
}

void test_SyntaxError(void)
{
  const HRESULT res = run_script(L"1=");
  TEST_ASSERT_EQUAL_HEX(SCRIPT_E_REPORTED, res);
}

void test_MissingFunc(void)
{
  const HRESULT res = run_script(L"IDoNotExist 1, 2, 3");
  // this throws a runtime error
  TEST_ASSERT_EQUAL(0, res);
}

void test_parser(void)
{
  const WCHAR* code = L"MsgBox \"Hello from VBScript!\"";
  parser_ctx_t ctx = {0};
  const HRESULT res = parse_script(&ctx, code, L"", 0);
  TEST_ASSERT_EQUAL(0, res);
  TEST_ASSERT_EQUAL_STRING(ctx.code, code);
}

void test_parser_error(void)
{
  parser_ctx_t ctx = {0};
  const WCHAR *code = L"1=";
  const HRESULT res = parse_script(&ctx, code, L"", 0);
  TEST_ASSERT_EQUAL_HEX(E_FAIL, res);
  TEST_ASSERT_EQUAL(ctx.error_loc, 0);
}

void test_parser_class(void)
{
  const WCHAR* code = L"Class TestClass\nEnd Class";
  parser_ctx_t ctx = {0};
  const HRESULT res = parse_script(&ctx, code, L"", 0);
  TEST_ASSERT_EQUAL(0, res);
  TEST_ASSERT_EQUAL_STRING(ctx.code, code);
  TEST_ASSERT_EQUAL(1, count_classes(ctx));
}

void test_parser_expression(void)
{
  parser_ctx_t ctx = {0};
  const HRESULT res = parse_script(&ctx, L"1+1", L"", SCRIPTTEXT_ISEXPRESSION);
  TEST_ASSERT_EQUAL(0, res);
}

void test_compile(void)
{
  const WCHAR* code = L"MsgBox \"Hello from VBScript!\"";

  script_ctx_t *script_ctx = malloc(sizeof(script_ctx_t));
  HRESULT hr = create_script_context(script_ctx);
  TEST_ASSERT_EQUAL_HEX(0, hr);

  vbscode_t* ret;
  hr = compile_script(script_ctx, code, NULL, L"", 0, 0, 0, &ret);
  TEST_ASSERT_EQUAL(0, hr);
  TEST_ASSERT_EQUAL_STRING(ret->source, code);

  free_script_context(script_ctx);
}

void test_compile_fail(void)
{
  const WCHAR *code = L"1=";

  script_ctx_t *script_ctx = malloc(sizeof(script_ctx_t));
  HRESULT hr = create_script_context(script_ctx);
  TEST_ASSERT_EQUAL_HEX(0, hr);

  vbscode_t* ret;

  hr = compile_script(script_ctx, code, NULL, L"", 0, 0, 0, &ret);
  TEST_ASSERT_EQUAL_HEX(SCRIPT_E_REPORTED, hr);
  // ret at this point seems to point to invalid memory as we get a segfault

  free_script_context(script_ctx);
}

void test_run_expression(void)
{
  VARIANT expression_result = {0};
  const WCHAR* code = L"1+1";
  const HRESULT res = run_expression(code, &expression_result, SCRIPTTEXT_ISEXPRESSION);
  TEST_ASSERT_EQUAL_HEX(0, res);

  TEST_ASSERT_EQUAL(2, V_I4(&expression_result));
}

void test_run_expression_error_parser(void)
{
  VARIANT expression_result = {0};
  const WCHAR* code = L"1=";
  const HRESULT res = run_expression(code, &expression_result, 0);
  TEST_ASSERT_EQUAL_HEX(SCRIPT_E_REPORTED, res);
}

void test_run_expression_not_explicit(void)
{
  VARIANT expression_result = {0};
  const WCHAR* code = L"a+1";
  const int flags = SCRIPTTEXT_ISEXPRESSION;
  const HRESULT res = run_expression(code, &expression_result, flags);
  TEST_ASSERT_EQUAL_HEX(0, res);
  // a does not exist, therefore it is 0, sum is 1
  TEST_ASSERT_EQUAL(1, V_I2(&expression_result));
}

void test_run_expression_explicit_error(void)
{
  VARIANT expression_result = {0};
  const WCHAR* code = L"Option Explicit\na+1";
  // INFO we can't use SCRIPTTEXT_ISEXPRESSION here
  // this indicates to the parser that we are parsing an expression.
  // If we put stuff like Option Explicit in the script in front of the actual expression it will fail.
  const int flags = 0;// SCRIPTTEXT_ISEXPRESSION
  const HRESULT res = run_expression(code, &expression_result, flags);
  // this should fail
  TEST_ASSERT_EQUAL_HEX(SCRIPT_E_REPORTED, res);
}

/// See https://bugs.winehq.org/show_bug.cgi?id=54177
void test_issue_54177(void)
{
  const WCHAR* code = L"Sub TestWithBracketsAtStartFirstArg(a)\n"
  "Call ok(a=2, \"a = \" & a & \" (expected 2)\")\n"
  "End Sub\n"
  "TestWithBracketsAtStartFirstArg (1) + 1";

  parser_ctx_t ctx = {0};
  const HRESULT res = parse_script(&ctx, code, L"", 0);
  TEST_ASSERT_EQUAL_HEX(0, res);
}