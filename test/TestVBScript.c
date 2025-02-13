#include <activscp.h>

#include "unity.h"
#include "utils.h"

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

void test_MsgBox(void)
{
  HRESULT res = run_script(L"MsgBox \"Hello from VBScript!\"");
  TEST_ASSERT_EQUAL(0, res);
}

void test_SyntaxError(void)
{
  HRESULT res = run_script(L"1=");
  TEST_ASSERT_EQUAL_HEX(SCRIPT_E_REPORTED, res);
}

void test_MissingFunc(void)
{
  HRESULT res = run_script(L"IDoNotExist 1, 2, 3");
  // this throws a runtime error
  TEST_ASSERT_EQUAL(0, res);
}

