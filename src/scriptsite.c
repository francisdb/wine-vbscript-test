#include <oleauto.h>
#include <zlog.h>
#include "scriptsite.h"
#include "utils.h"

static LastErrorInfo g_lastErrorInfo = {0};

const LastErrorInfo* GetLastErrorInfo() {
    return &g_lastErrorInfo;
}
void ClearErrorInfo(){
    g_lastErrorInfo.scode = 0;
}

HRESULT OnScriptError(IActiveScriptError *pscripterror) {
    DWORD dwCookie;
    ULONG nLine;
    LONG nChar;
    BSTR bstr = NULL;
    EXCEPINFO exception = {0};
    HRESULT hr;

    zlog_category_t *c = zlog_get_category("on_script_error");

    hr = pscripterror->lpVtbl->GetSourcePosition(pscripterror, &dwCookie, &nLine, &nChar);
    if (FAILED(hr)) {
        zlog_debug(c, "OnScriptError: Failed to get source position: 0x%08lx %s", hr, HResultToString(hr));
        return hr;
    }

    hr = pscripterror->lpVtbl->GetSourceLineText(pscripterror, &bstr);
    if (FAILED(hr)) {
        zlog_debug(c, "OnScriptError: Failed to get source line text: 0x%08lx %s", hr, HResultToString(hr));
    }

    hr = pscripterror->lpVtbl->GetExceptionInfo(pscripterror, &exception);
    if (FAILED(hr)) {
        zlog_debug(c, "OnScriptError: Failed to get exception info: 0x%08lx %s", hr, HResultToString(hr));
        SysFreeString(bstr);
    }

    nLine++;

    const char* szT = (exception.bstrDescription) ? ConvertBSTRToString(exception.bstrDescription) : "Description unavailable";
    const char* szSource = (exception.bstrSource) ? ConvertBSTRToString(exception.bstrSource) : "Source unavailable";

    zlog_error(c, "OnScriptError: Script Error 0x%x at line %lu pos %d : %s - %s", exception.scode, nLine, nChar, szSource, szT);

    // Update the global last error info
    g_lastErrorInfo.scode = exception.scode;

    SysFreeString(bstr);
    SysFreeString(exception.bstrDescription);
    SysFreeString(exception.bstrSource);
    SysFreeString(exception.bstrHelpFile);

    return S_OK;
}


// Forward declarations of IActiveScriptSite methods
HRESULT STDMETHODCALLTYPE ScriptSite_QueryInterface(IActiveScriptSite *This, REFIID riid, void **ppvObject);
ULONG STDMETHODCALLTYPE ScriptSite_AddRef(IActiveScriptSite *This);
ULONG STDMETHODCALLTYPE ScriptSite_Release(IActiveScriptSite *This);
HRESULT STDMETHODCALLTYPE ScriptSite_GetLCID(IActiveScriptSite *This, LCID *plcid);
HRESULT STDMETHODCALLTYPE ScriptSite_GetItemInfo(IActiveScriptSite *This, LPCOLESTR pstrName, DWORD dwReturnMask, IUnknown **ppiunkItem, ITypeInfo **ppti);
HRESULT STDMETHODCALLTYPE ScriptSite_GetDocVersionString(IActiveScriptSite *This, BSTR *pbstrVersion);
HRESULT STDMETHODCALLTYPE ScriptSite_OnScriptTerminate(IActiveScriptSite *This, const VARIANT *pvarResult, const EXCEPINFO *pexcepinfo);
HRESULT STDMETHODCALLTYPE ScriptSite_OnStateChange(IActiveScriptSite *This, SCRIPTSTATE ssScriptState);
HRESULT STDMETHODCALLTYPE ScriptSite_OnScriptError(IActiveScriptSite *This, IActiveScriptError *pscripterror);
HRESULT STDMETHODCALLTYPE ScriptSite_OnEnterScript(IActiveScriptSite *This);
HRESULT STDMETHODCALLTYPE ScriptSite_OnLeaveScript(IActiveScriptSite *This);

// Define the IActiveScriptSite virtual table
static const IActiveScriptSiteVtbl ScriptSite_Vtbl = {
    ScriptSite_QueryInterface,
    ScriptSite_AddRef,
    ScriptSite_Release,
    ScriptSite_GetLCID,
    ScriptSite_GetItemInfo,
    ScriptSite_GetDocVersionString,
    ScriptSite_OnScriptTerminate,
    ScriptSite_OnStateChange,
    ScriptSite_OnScriptError,
    ScriptSite_OnEnterScript,
    ScriptSite_OnLeaveScript
};

// Implement the IActiveScriptSite methods
HRESULT STDMETHODCALLTYPE ScriptSite_QueryInterface(IActiveScriptSite *This, REFIID riid, void **ppvObject) {
    if (IsEqualIID(riid, &IID_IUnknown) || IsEqualIID(riid, &IID_IActiveScriptSite)) {
        *ppvObject = This;
        ScriptSite_AddRef(This);
        return S_OK;
    }
    *ppvObject = NULL;
    return E_NOINTERFACE;
}

ULONG STDMETHODCALLTYPE ScriptSite_AddRef(IActiveScriptSite *This) {
    ScriptSite *site = (ScriptSite *)This;
    return InterlockedIncrement(&site->ref);
}

ULONG STDMETHODCALLTYPE ScriptSite_Release(IActiveScriptSite *This) {
    zlog_info(zlog_get_category("scriptsite"), "OnScriptRelease");
    ScriptSite *site = (ScriptSite *)This;
    ULONG ref = InterlockedDecrement(&site->ref);
    if (ref == 0) {
        free(site);
    }
    return ref;
}

HRESULT STDMETHODCALLTYPE ScriptSite_GetLCID(IActiveScriptSite *This, LCID *plcid) {
    *plcid = LOCALE_USER_DEFAULT;
    return S_OK;
}

HRESULT STDMETHODCALLTYPE ScriptSite_GetItemInfo(IActiveScriptSite *This, LPCOLESTR pstrName, DWORD dwReturnMask, IUnknown **ppiunkItem, ITypeInfo **ppti) {
    return TYPE_E_ELEMENTNOTFOUND;
}

HRESULT STDMETHODCALLTYPE ScriptSite_GetDocVersionString(IActiveScriptSite *This, BSTR *pbstrVersion) {
    *pbstrVersion = SysAllocString(L"1.0");
    return S_OK;
}

HRESULT STDMETHODCALLTYPE ScriptSite_OnScriptTerminate(IActiveScriptSite *This, const VARIANT *pvarResult, const EXCEPINFO *pexcepinfo) {
    zlog_info(zlog_get_category("scriptsite"), "OnScriptTerminate");
    return S_OK;
}

HRESULT STDMETHODCALLTYPE ScriptSite_OnStateChange(IActiveScriptSite *This, SCRIPTSTATE ssScriptState) {
    return S_OK;
}

HRESULT STDMETHODCALLTYPE ScriptSite_OnScriptError(IActiveScriptSite *This, IActiveScriptError *pscripterror) {
    return OnScriptError(pscripterror);
}

HRESULT STDMETHODCALLTYPE ScriptSite_OnEnterScript(IActiveScriptSite *This) {
    zlog_info(zlog_get_category("scriptsite"), "OnEnterScript");
    return S_OK;
}

HRESULT STDMETHODCALLTYPE ScriptSite_OnLeaveScript(IActiveScriptSite *This) {
    zlog_info(zlog_get_category("scriptsite"), "OnLeaveScript");
    return S_OK;
}

// Function to create an instance of ScriptSite
ScriptSite *CreateScriptSite() {
    ScriptSite *site = (ScriptSite *)malloc(sizeof(ScriptSite));
    if (site) {
        site->IActiveScriptSite_iface.lpVtbl = &ScriptSite_Vtbl;
        site->ref = 1;
    }
    return site;
}
