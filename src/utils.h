#ifndef UTILS_H
#define UTILS_H

#include <oleauto.h>

const char* ConvertBSTRToString(BSTR bstr);
const char* HResultToString(HRESULT hr);
int run_script(const wchar_t* script);

#endif // UTILS_H