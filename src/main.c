#include <stdio.h>
#include <oleauto.h>
#include <zlog.h>
#include "utils.h"



int main(void) {

    //int rc = zlog_init("/etc/zlog.conf");
    int rc = zlog_init_from_string("[formats]\n"
                                   "simple = \"%-20c %-5V - %m%n\"\n"
                                   "[rules]\n"
                                   "*.DEBUG    >stdout;simple\n");
    if (rc) {
        printf("zlog init failed\n");
        return -1;
    }
    zlog_category_t* c = zlog_get_category("main");

    if (!c) {
        printf("get cat fail\n");
        zlog_fini();
        return -2;
    }


    zlog_info(c, "Testing VBScript");

    HRESULT hr;

    const wchar_t* script_msgbox = L"MsgBox \"Hello from VBScript!\"";
    hr = run_script(script_msgbox);

    const wchar_t* script_debug = L"debug.print \"Hello from VBScript!\"";
    hr = run_script(script_debug);
    // This seems to fail only with onScriptError
    if (FAILED(hr)) {
        fprintf(stderr, "Failed to execute script_debug: 0x%08lx %s\n%ls\n", hr, HResultToString(hr), script_debug);
    }

    const wchar_t* script_err = L"1=";
    hr = run_script(script_err);

    zlog_fini();
    return hr;
}
