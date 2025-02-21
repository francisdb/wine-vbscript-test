
#define UNITY_OUTPUT_COLOR

#include <activscp.h>
#include <vbscript.h>
#include <parse.h>
#include <parser.tab.h>
#include <scriptsite.h>
#include <zlog.h>


#include "unity.h"
#include "utils.h"

// helper functions

static const unsigned op_move[] = {
#define X(x,n,a,b) n,
  OP_LIST
#undef X
};

const char* op_names[] = {
#define X(x,n,a,b) #x,
  OP_LIST
#undef X
};

// contains all caracters defined in ascii
const char* ascii_strings[] = {
  "NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL",
  "BS", "HT", "LF", "VT", "FF", "CR", "SO", "SI",
  "DLE", "DC1", "DC2", "DC3", "DC4", "NAK", "SYN", "ETB",
  "CAN", "EM", "SUB", "ESC", "FS", "GS", "RS", "US",
  "SPACE", "!", "\"", "#", "$", "%", "&", "'",
  "(", ")", "*", "+", ",", "-", ".", "/",
  "0", "1", "2", "3", "4", "5", "6", "7",
  "8", "9", ":", ";", "<", "=", ">", "?",
  "@", "A", "B", "C", "D", "E", "F", "G",
  "H", "I", "J", "K", "L", "M", "N", "O",
  "P", "Q", "R", "S", "T", "U", "V", "W",
  "X", "Y", "Z", "[", "\\", "]", "^", "_",
  "`", "a", "b", "c", "d", "e", "f", "g",
  "h", "i", "j", "k", "l", "m", "n", "o",
  "p", "q", "r", "s", "t", "u", "v", "w",
  "x", "y", "z", "{", "|", "}", "~", "DEL"
};

const char* print_token(const parser_token_kind_t token)
{
  switch (token)
  {
  case tInt:
    return "tInt";
  case tDouble:
    return "tDouble";
  case tDate:
    return "tDate";
  case tString:
    return "tString";
  case tIdentifier:
    return "tIdentifier";
  case tERROR:
    return "tERROR";
  case tEXPLICIT:
    return "tEXPLICIT";
  case tPROPERTY:
    return "tPROPERTY";
  case tNL:
    return "tNL";
  case tSUB:
    return "tSUB";
  case tEND:
    return "tEND";
  case PARSER_EOF:
    return "PARSER_EOF";
  case tEMPTYBRACKETS:
    return "tEMPTYBRACKETS";
  // case tEXPRLBRACKET:
  //   return "tEXPRLBRACKET";
  case tLTEQ:
    return "tLTEQ";
  case tGTEQ:
    return "tGTEQ";
  case tNEQ:
    return "tNEQ";
  case tSTOP:
    return "tSTOP";
  case tME:
    return "tME";
  case tREM:
    return "tREM";
  case tDOT:
    return "tDOT";
  case tTRUE:
    return "tTRUE";
  case tFALSE:
    return "tFALSE";
  case tNOT:
    return "tNOT";
  case tAND:
    return "tAND";
  case tOR:
    return "tOR";
  case tXOR:
    return "tXOR";
  case tEQV:
    return "tEQV";
  case tIMP:
    return "tIMP";
  case tIS:
    return "tIS";
  case tMOD:
    return "tMOD";
  case tCALL:
    return "tCALL";
  case tFUNCTION:
    return "tFUNCTION";
  case tGET:
    return "tGET";
  case tLET:
    return "tLET";
  case tCONST:
    return "tCONST";
  case tDIM:
    return "tDIM";
  case tREDIM:
    return "tREDIM";
  case tPRESERVE:
    return "tPRESERVE";
  case tIF:
    return "tIF";
  case tELSE:
    return "tELSE";
  case tELSEIF:
    return "tELSEIF";
  case tTHEN:
    return "tTHEN";
  case tEXIT:
    return "tEXIT";
  case tWHILE:
    return "tWHILE";
  case tWEND:
    return "tWEND";
  case tDO:
    return "tDO";
  case tLOOP:
    return "tLOOP";
  case tUNTIL:
    return "tUNTIL";
  case tFOR:
    return "tFOR";
  case tTO:
    return "tTO";
  case tEACH:
    return "tEACH";
  case tIN:
    return "tIN";
  case tSELECT:
    return "tSELECT";
  case tCASE:
    return "tCASE";
  case tWITH:
    return "tWITH";
  case tBYREF:
    return "tBYREF";
  case tBYVAL:
    return "tBYVAL";
  case tOPTION:
    return "tOPTION";
  case tNOTHING:
    return "tNOTHING";
  case tEMPTY:
    return "tEMPTY";
  case tNULL:
    return "tNULL";
  case tCLASS:
    return "tCLASS";
  case tSET:
    return "tSET";
  case tNEW:
    return "tNEW";
  case tPUBLIC:
    return "tPUBLIC";
  case tPRIVATE:
    return "tPRIVATE";
  case tNEXT:
    return "tNEXT";
  case tON:
    return "tON";
  case tRESUME:
    return "tRESUME";
  case tGOTO:
    return "tGOTO";
  default:
    if (token >= 0 && token <= 127)
      return ascii_strings[token];
    return "???";
  }
}

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
    list_init(&ctx->objects);

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
  // To see wind log messages set the level for external_log to DEBUG
  const int rc = zlog_init_from_string("[formats]\n"
  "simple = \"%-20c %-5V - %m%n\"\n"
  "[rules]\n"
  "*.DEBUG    >stdout;simple\n");
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
  ClearErrorInfo();
}

void tearDown(void)
{
}

parser_token_kind_t* lex_all(const WCHAR *ptr, int max_tokens)
{
  parser_ctx_t ctx = {0};
  ctx.ptr = ptr;
  ctx.end = ctx.ptr + wcslen(ctx.ptr);
  unsigned loc = 0;
  void *lval = malloc(sizeof(void*));

  parser_token_kind_t* results = malloc(sizeof(parser_token_kind_t*) * max_tokens);

  parser_token_kind_t ret = PARSER_UNDEF;
  int i = 0;
  while (ret != PARSER_EOF && i < max_tokens)
  {
    ret = parser_lex(lval, &loc, &ctx);
    results[i] = ret;
    i++;
  }
  return results;
}

/// lex all and print tokens
void print_tokens(const WCHAR *ptr)
{
  parser_ctx_t ctx = {0};
  ctx.ptr = ptr;
  ctx.end = ctx.ptr + wcslen(ctx.ptr);
  unsigned loc = 0;
  void *lval = malloc(sizeof(void*));

  parser_token_kind_t ret = PARSER_UNDEF;
  while (ret != PARSER_EOF)
  {
    ret = parser_lex(lval, &loc, &ctx);
    printf("Token: %3d %s\n", ret, print_token(ret));
  }
  free(lval);
}

void print_instructions(vbscode_t* code)
{
  instr_t* instr = code->instrs;
  while(instr->op != OP_ret)
  {
    printf("instr @ pos %d: %s\n", instr->loc, op_names[instr->op]);
    //printf("  move: %d\n", op_move[instr->op]);
    //instr += op_move[instr->op];
    // TODO how do we know to stop?
    instr++;
  }
}


// void test_lexer(void)
// {
//   const parser_token_kind_t* tokens = lex_all(L"10+1", 10);
//   const parser_token_kind_t expected[5] = {
//     tInt,
//     '+',
//     tInt,
//     tNL,
//     PARSER_EOF
//   };
//   TEST_ASSERT_EQUAL_INT16_ARRAY(expected, tokens, 5);
// }
//
void test_MsgBox(void)
{
  const HRESULT res = run_script(L"MsgBox \"Hello from VBScript!\"");
  TEST_ASSERT_EQUAL(0, res);
}
//
// void test_SyntaxError(void)
// {
//   const HRESULT res = run_script(L"1=");
//   TEST_ASSERT_EQUAL_HEX(SCRIPT_E_REPORTED, res);
//   const LastErrorInfo* errorInfo = GetLastErrorInfo();
//   TEST_ASSERT_EQUAL_HEX(E_FAIL, errorInfo->scode);
// }
//
// void test_MissingFunc(void)
// {
//   const HRESULT res = run_script(L"IDoNotExist 1, 2, 3");
//   // this throws a runtime error
//   TEST_ASSERT_EQUAL(0, res);
//   const LastErrorInfo* errorInfo = GetLastErrorInfo();
//   const SCODE expected = 0x800A01B6; //Object doesn’t  support this property or method
//   TEST_ASSERT_EQUAL_HEX(expected, errorInfo->scode);
// }
//
// void test_parser(void)
// {
//   const WCHAR* code = L"MsgBox \"Hello from VBScript!\"";
//   parser_ctx_t ctx = {0};
//   const HRESULT res = parse_script(&ctx, code, L"", 0);
//   TEST_ASSERT_EQUAL(0, res);
//   TEST_ASSERT_EQUAL_STRING(ctx.code, code);
// }
//
// void test_parser_error(void)
// {
//   parser_ctx_t ctx = {0};
//   const WCHAR *code = L"1=";
//   const HRESULT res = parse_script(&ctx, code, L"", 0);
//   TEST_ASSERT_EQUAL_HEX(E_FAIL, res);
//   TEST_ASSERT_EQUAL(ctx.error_loc, 0);
// }
//
// void test_parser_class(void)
// {
//   const WCHAR* code = L"Class TestClass\nEnd Class";
//   parser_ctx_t ctx = {0};
//   const HRESULT res = parse_script(&ctx, code, L"", 0);
//   TEST_ASSERT_EQUAL(0, res);
//   TEST_ASSERT_EQUAL_STRING(ctx.code, code);
//   TEST_ASSERT_EQUAL(1, count_classes(ctx));
// }
//
// void test_parser_expression(void)
// {
//   parser_ctx_t ctx = {0};
//   const HRESULT res = parse_script(&ctx, L"1+1", L"", SCRIPTTEXT_ISEXPRESSION);
//   TEST_ASSERT_EQUAL(0, res);
// }
//
// void test_compile(void)
// {
//   const WCHAR* code = L"MsgBox \"Hello from VBScript!\"";
//
//   script_ctx_t *script_ctx = malloc(sizeof(script_ctx_t));
//   HRESULT hr = create_script_context(script_ctx);
//   TEST_ASSERT_EQUAL_HEX(0, hr);
//
//   vbscode_t* ret;
//   hr = compile_script(script_ctx, code, NULL, L"", 0, 0, 0, &ret);
//   TEST_ASSERT_EQUAL(0, hr);
//   TEST_ASSERT_EQUAL_STRING(ret->source, code);
//
//   free_script_context(script_ctx);
// }
//
// void test_compile_fail(void)
// {
//   const WCHAR *code = L"1=";
//
//   script_ctx_t *script_ctx = malloc(sizeof(script_ctx_t));
//   HRESULT hr = create_script_context(script_ctx);
//   TEST_ASSERT_EQUAL_HEX(0, hr);
//
//   vbscode_t* ret;
//
//   hr = compile_script(script_ctx, code, NULL, L"", 0, 0, 0, &ret);
//   TEST_ASSERT_EQUAL_HEX(SCRIPT_E_REPORTED, hr);
//   // ret at this point seems to point to invalid memory as we get a segfault
//   const LastErrorInfo* errorInfo = GetLastErrorInfo();
//   TEST_ASSERT_EQUAL_HEX(E_FAIL, errorInfo->scode);
//
//   free_script_context(script_ctx);
// }
//
// void test_run_expression(void)
// {
//   VARIANT expression_result = {0};
//   const WCHAR* code = L"1+1";
//   const HRESULT res = run_expression(code, &expression_result, SCRIPTTEXT_ISEXPRESSION);
//   TEST_ASSERT_EQUAL_HEX(0, res);
//
//   TEST_ASSERT_EQUAL(2, V_I4(&expression_result));
// }
//
// void test_run_expression_error_parser(void)
// {
//   VARIANT expression_result = {0};
//   const WCHAR* code = L"1=";
//   const HRESULT res = run_expression(code, &expression_result, 0);
//   TEST_ASSERT_EQUAL_HEX(SCRIPT_E_REPORTED, res);
// }
//
// void test_run_expression_not_explicit(void)
// {
//   VARIANT expression_result = {0};
//   const WCHAR* code = L"a+1";
//   const int flags = SCRIPTTEXT_ISEXPRESSION;
//   const HRESULT res = run_expression(code, &expression_result, flags);
//   TEST_ASSERT_EQUAL_HEX(0, res);
//   // a does not exist, therefore it is 0, sum is 1
//   TEST_ASSERT_EQUAL(1, V_I2(&expression_result));
// }
//
// void test_run_expression_explicit_error(void)
// {
//   VARIANT expression_result = {0};
//   const WCHAR* code = L"Option Explicit\na+1";
//   // INFO we can't use SCRIPTTEXT_ISEXPRESSION here
//   // this indicates to the parser that we are parsing an expression.
//   // If we put stuff like Option Explicit in the script in front of the actual expression it will fail.
//   const int flags = 0;// SCRIPTTEXT_ISEXPRESSION
//   const HRESULT res = run_expression(code, &expression_result, flags);
//   // this should fail
//   TEST_ASSERT_EQUAL_HEX(SCRIPT_E_REPORTED, res);
// }
//
// /// See https://bugs.winehq.org/show_bug.cgi?id=54177
// void test_issue_54177_parse1(void)
// {
//   const WCHAR* code = L"Sub Test(a)\n"
//   "Call ok(a=2, \"a = \" & a & \" (expected 2)\")\n"
//   "End Sub\n"
//   "Test (1) + 1";
//
//   parser_ctx_t ctx = {0};
//   const HRESULT res = parse_script(&ctx, code, L"", 0);
//   TEST_ASSERT_EQUAL_HEX(0, res);
// }
//
// void test_issue_54177_parse2(void)
// {
//   // Test is a sub with single argument
//   const WCHAR* code = L"Sub Test(a)\n"
//   "Call ok(a=2, \"a = \" & a & \" (expected 2)\")\n"
//   "End Sub\n"
//   "Test 1 + (1)";
//
//   //print_tokens(code);
//
//   parser_ctx_t ctx = {0};
//   const HRESULT res = parse_script(&ctx, code, L"", 0);
//   TEST_ASSERT_EQUAL_HEX(0, res);
// }
//
// void test_issue_54177_parse3(void)
// {
//   const WCHAR* code = L"Function Test(a)\n"
//   "Test = a + 1\n"
//   "End Function\n"
//   "Dim r: r = Test(1) + 1";
//
//   parser_ctx_t ctx = {0};
//   const HRESULT res = parse_script(&ctx, code, L"", 0);
//   TEST_ASSERT_EQUAL_HEX(0, res);
// }
//
// void test_issue_54177_compile(void)
// {
//   const WCHAR* code = L"Sub Test(a)\n"
//   "Call ok(a=2, \"a = \" & a & \" (expected 2)\")\n"
//   "End Sub\n"
//   "Test (1) + 1";
//
//   script_ctx_t *script_ctx = malloc(sizeof(script_ctx_t));
//   HRESULT hr = create_script_context(script_ctx);
//   TEST_ASSERT_EQUAL_HEX(0, hr);
//
//   vbscode_t* ret;
//   hr = compile_script(script_ctx, code, NULL, L"", 0, 0, 0, &ret);
//   TEST_ASSERT_EQUAL(0, hr);
//   TEST_ASSERT_EQUAL_STRING(ret->source, code);
//
//   free_script_context(script_ctx);
// }
//
// void test_issue_54177_run1(void){
//   const WCHAR* code = L"Sub Test(a)\n"
//   "MsgBox \"a = \" & a\n"
//   "End Sub\n"
//   "Test 1 + (1)";
//
//   VARIANT expression_result = {0};
//   HRESULT hr = run_expression(code, &expression_result,0);
//   TEST_ASSERT_EQUAL_HEX(0, hr);
//   TEST_ASSERT_EQUAL(VT_EMPTY, V_VT(&expression_result));
// }
//
// void test_issue_54177_run2(void){
//   const WCHAR* code = L"Sub Test(a)\n"
//   "MsgBox \"a = \" & a\n"
//   "End Sub\n"
//   "Test (1) + 1";
//
//   VARIANT expression_result = {0};
//   HRESULT hr = run_expression(code, &expression_result,0);
//   TEST_ASSERT_EQUAL_HEX(0, hr);
//   TEST_ASSERT_EQUAL(VT_EMPTY, V_VT(&expression_result));
// }
//
// void test_issue_54177_run3(void)
// {
//   const WCHAR* code = L"Function Test(a)\n"
//   "Test = a + 1\n"
//   "End Function\n"
//   "Dim r: r = Test(1) + 1\n"
//   "MsgBox \"result = \" & r";
//
//   VARIANT expression_result = {0};
//   HRESULT hr = run_expression(code, &expression_result,0);
//   TEST_ASSERT_EQUAL_HEX(0, hr);
//   TEST_ASSERT_EQUAL(VT_EMPTY, V_VT(&expression_result));
// }
//
/// See https://bugs.winehq.org/show_bug.cgi?id=41119

const WCHAR* code_for_41119 = L"class TestPropSyntax\n"
"public prop\n"
"function getProp()\n"
"    set getProp = prop\n"
"end function\n"
"public default property get def()\n"
"    def = \"\"\n"
"end property\n"
"end class\n"
"Dim arr(3)\n"
"set arr(0) = new TestPropSyntax\n"
"arr(0).prop = 1\n"
"MsgBox \"arr(0) = \" & arr(0).prop\n"
"function f2(x,y)\n"
"end function\n"
"f2 1 = 1, 2\n"
"function f1(x)\n"
"    MsgBox \"x = \" & x\n"
"end function\n"
"f1 1 = 1\n"
"f1 1 = (1)\n"
"f1 not 1 = 0\n"
"arr (0) = 2 xor -2";

// void test_issue_41119_parse(void)
// {
//   parser_ctx_t ctx = {0};
//   const HRESULT res = parse_script(&ctx, code_for_41119, L"", 0);
//   TEST_ASSERT_EQUAL_HEX(0, res);
// }
//
// void test_issue_41119_compile(void) {
//   script_ctx_t *script_ctx = malloc(sizeof(script_ctx_t));
//   HRESULT hr = create_script_context(script_ctx);
//   TEST_ASSERT_EQUAL_HEX(0, hr);
//
//   vbscode_t* ret;
//   hr = compile_script(script_ctx, code_for_41119, NULL, L"", 0, 0, 0, &ret);
//   TEST_ASSERT_EQUAL(0, hr);
//   TEST_ASSERT_EQUAL_STRING(ret->source, code_for_41119);
//
//   free_script_context(script_ctx);
// }
//
// void test_issue_41119_run(void) {
//   VARIANT expression_result = {0};
//   const HRESULT hr = run_expression(code_for_41119, &expression_result,0);
//   TEST_ASSERT_EQUAL_HEX(0, hr);
//   TEST_ASSERT_EQUAL(VT_EMPTY, V_VT(&expression_result));
// }

// const WCHAR* code_for_41119_minimal = L"Dim arr(3)\n"
// "set arr(0) = new TestPropSyntax\n"
// "arr(0).prop = 1\n";



const WCHAR* code_for_41119_minimal = L"class TestPropSyntax\n"
"public prop\n"
"end class\n"
"Dim arr(3)\n"
"set arr(0) = new TestPropSyntax\n"
"arr(0).prop = 1\n"
"set arr(1) = new TestPropSyntax\n"
"arr (0) = 2 xor -2\n"
"MsgBox \"hello\"";

// void test_issue_41119_parse_minimal(void) {
//   parser_ctx_t ctx = {0};
//   const HRESULT hr = parse_script(&ctx, code_for_41119_minimal, L"", 0);
//   print_tokens(code_for_41119_minimal);
//   TEST_ASSERT_EQUAL_HEX(0, hr);
// }

// void test_compile_minimal(void) {
//   script_ctx_t *script_ctx = malloc(sizeof(script_ctx_t));
//   HRESULT hr = create_script_context(script_ctx);
//   TEST_ASSERT_EQUAL_HEX(0, hr);
//
//   vbscode_t* code;
//   hr = compile_script(script_ctx, code_for_41119_minimal, NULL, L"", 0, 0, 0, &code);
//   TEST_ASSERT_EQUAL(0, hr);
//   TEST_ASSERT_EQUAL_STRING(code->source, code_for_41119_minimal);
//
//   // not public, only in compile.c and the compile_ctx is not exposed
//   // dump_code(compile_ctx, code);
//   print_instructions(code);
//
//   free_script_context(script_ctx);
// }

void test_issue_41119_run_minimal(void) {
  VARIANT expression_result = {0};
  const HRESULT hr = run_expression(code_for_41119_minimal, &expression_result,0);
  TEST_ASSERT_EQUAL_HEX(0, hr);
  TEST_ASSERT_EQUAL(VT_EMPTY, V_VT(&expression_result));
}
