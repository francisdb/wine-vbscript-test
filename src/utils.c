#include <activscp.h>
#include <zlog.h>
#include <vbscript_classes.h>
#include "scriptsite.h"
#include "utils.h"

const char* ConvertBSTRToString(BSTR bstr) {
    if (!bstr) {
        return NULL;
    }

    // Get the length of the BSTR
    int lenW = SysStringLen(bstr);
    if (lenW == 0) {
        return NULL;
    }

    // Convert BSTR to a wide character string
    int lenA = WideCharToMultiByte(CP_ACP, 0, bstr, lenW, NULL, 0, NULL, NULL);
    if (lenA == 0) {
        return NULL;
    }

    // Allocate memory for the char* string
    char* szOut = (char*)malloc(lenA + 1);
    if (!szOut) {
        return NULL;
    }

    // Convert the wide character string to a char* string
    WideCharToMultiByte(CP_ACP, 0, bstr, lenW, szOut, lenA, NULL, NULL);
    szOut[lenA] = '\0';

    return szOut;
}

const char* HResultToString(HRESULT hr) {
    switch (hr) {
    case S_OK: return "Operation successful";
    case E_ABORT: return "Operation aborted";
    case E_ACCESSDENIED: return "General access denied error";
    case E_FAIL: return "Unspecified failure";
    case E_HANDLE: return "Handle that is not valid";
    case E_INVALIDARG: return "One or more arguments are not valid";
    case E_NOINTERFACE: return "No such interface supported";
    case E_NOTIMPL: return "E_NOTIMPL: Not implemented";
    case E_OUTOFMEMORY: return "Failed to allocate necessary memory";
    case E_POINTER: return "Pointer that is not valid";
    case E_UNEXPECTED: return "Unexpected failure";
    case SCRIPT_E_REPORTED: return "SCRIPT_E_REPORTED: Error already reported using OnScriptError";
    default: return "Unknown error code";
    }
}

HRESULT run_script(const wchar_t* script)
{
    ScriptSite *site = CreateScriptSite();

    zlog_category_t* c = zlog_get_category("run_script");


    // TODO run the vbscript directly without the IID_IActiveScriptParse interface

    IActiveScriptParse* m_pScriptParse = NULL;
    IActiveScript* m_pScript = NULL;

    const HRESULT vbScriptResult = CoCreateInstance(
        &CLSID_VBScript, 0,
        CLSCTX_ALL/*CLSCTX_INPROC_SERVER*/,
        &IID_IActiveScriptParse,
        (LPVOID*)&m_pScriptParse
    ); //!! CLSCTX_INPROC_SERVER good enough?!
    if (vbScriptResult != S_OK)
        return vbScriptResult;

    // Query for IActiveScript interface
    HRESULT hr = m_pScriptParse->lpVtbl->QueryInterface(m_pScriptParse, &IID_IActiveScript, (void**)&m_pScript);
    if (FAILED(hr)) {
        zlog_error(c, "Failed to query IActiveScript interface: 0x%08lx %s", hr, HResultToString(hr));
        m_pScriptParse->lpVtbl->Release(m_pScriptParse);
        //CoUninitialize();
        return hr;
    }

    // Initialize the script engine
    hr = m_pScriptParse->lpVtbl->InitNew(m_pScriptParse);
    if (FAILED(hr)) {
        zlog_error(c, "Failed to initialize script engine: 0x%08lx %s", hr, HResultToString(hr));
        m_pScript->lpVtbl->Release(m_pScript);
        m_pScriptParse->lpVtbl->Release(m_pScriptParse);
        //CoUninitialize();
        return hr;
    }

    // Set the script site
    hr = m_pScript->lpVtbl->SetScriptSite(m_pScript, (IActiveScriptSite*)site);
    if (FAILED(hr)) {
        zlog_error(c, "Failed to set script site: 0x%08lx %s", hr, HResultToString(hr));
        m_pScript->lpVtbl->Release(m_pScript);
        m_pScriptParse->lpVtbl->Release(m_pScriptParse);
        //CoUninitialize();
        return hr;
    }

    EXCEPINFO excepInfo;
    hr = m_pScriptParse->lpVtbl->ParseScriptText(m_pScriptParse, script, NULL, NULL, NULL, 0, 0, 0, NULL, &excepInfo);
    if (FAILED(hr)) {
        zlog_error(c, "Failed to execute script: 0x%08lx %s: %ls", hr, HResultToString(hr), script);
        // if (excepInfo.bstrDescription) {
        //     //fprintf(stderr, "Description: %S\n", excepInfo.bstrDescription);
        //     //SysFreeString(excepInfo.bstrDescription);
        // }
        return hr;
    }

    // now run the script
    hr = m_pScript->lpVtbl->SetScriptState(m_pScript, SCRIPTSTATE_CONNECTED);
    if (FAILED(hr)) {
        zlog_error(c, "Failed to set script state: 0x%08lx %s", hr, HResultToString(hr));
        m_pScript->lpVtbl->Release(m_pScript);
        m_pScriptParse->lpVtbl->Release(m_pScriptParse);
        //CoUninitialize();
        return hr;
    }

    // Clean up
    m_pScript->lpVtbl->Close(m_pScript);
    m_pScript->lpVtbl->Release(m_pScript);
    m_pScriptParse->lpVtbl->Release(m_pScriptParse);
    // CoUninitialize();

    return 0;
}