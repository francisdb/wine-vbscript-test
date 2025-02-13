#include <oleauto.h>

extern HRESULT external_open_storage(const OLECHAR* pwcsName, IStorage* pstgPriority, DWORD grfMode, SNB snbExclude, DWORD reserved, IStorage **ppstgOpen);
extern HRESULT external_create_object(const WCHAR *progid, IClassFactory* cf, IUnknown* obj);
extern void external_log_info(const char* format, ...);
extern void external_log_debug(const char* format, ...);
extern void external_log_error(const char* format, ...);
