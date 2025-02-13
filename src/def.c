#include "def.h"
#include <zlog.h>

HRESULT external_open_storage(const OLECHAR* pwcsName, IStorage* pstgPriority, DWORD grfMode, SNB snbExclude, DWORD reserved, IStorage** ppstgOpen)
{
    // return unimplemeted
    return E_NOTIMPL;
}

HRESULT external_create_object(const WCHAR* progid, IClassFactory* cf, IUnknown* obj)
{
    // return unimplemeted
    return E_NOTIMPL;
}

void external_log_info(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    vzlog_info(zlog_get_category("external_log"), format, args);
    va_end(args);
}

void external_log_debug(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    vzlog_debug(zlog_get_category("external_log"), format, args);
    va_end(args);
}

void external_log_error(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    vzlog_error(zlog_get_category("external_log"), format, args);
    va_end(args);
}
