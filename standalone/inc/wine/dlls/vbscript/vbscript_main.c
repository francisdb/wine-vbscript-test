/*
 * Copyright 2011 Jacek Caban for CodeWeavers
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#include "initguid.h"

#include "vbscript.h"
#include "objsafe.h"
#include "mshtmhst.h"
#include "rpcproxy.h"
#include "vbscript_classes.h"
#include "vbsglobal.h"
#include "vbsregexp55.h"

#include "wine/debug.h"

WINE_DEFAULT_DEBUG_CHANNEL(vbscript);
WINE_DECLARE_DEBUG_CHANNEL(heap);

DEFINE_GUID(GUID_NULL,0,0,0,0,0,0,0,0,0,0,0);

static HINSTANCE vbscript_hinstance;
static ITypeInfo *dispatch_typeinfo;

BSTR get_vbscript_string(int id)
{
    WCHAR buf[512];
#ifndef __STANDALONE__
    if(!LoadStringW(vbscript_hinstance, id, buf, ARRAY_SIZE(buf))) return NULL;
#else
    switch (id) {
        case VBSE_ILLEGAL_FUNC_CALL:
            swprintf(buf, ARRAY_SIZE(buf), L"VBSE_ILLEGAL_FUNC_CALL");
            break;
        case VBSE_OVERFLOW:
            swprintf(buf, ARRAY_SIZE(buf), L"VBSE_OVERFLOW");
            break;
        case VBSE_OUT_OF_MEMORY:
            swprintf(buf, ARRAY_SIZE(buf), L"VBSE_OUT_OF_MEMORY");
            break;
        case VBSE_OUT_OF_BOUNDS:
            swprintf(buf, ARRAY_SIZE(buf), L"VBSE_OUT_OF_BOUNDS");
            break;
        case VBSE_ARRAY_LOCKED:
            swprintf(buf, ARRAY_SIZE(buf), L"VBSE_ARRAY_LOCKED");
            break;
        case VBSE_TYPE_MISMATCH:
            swprintf(buf, ARRAY_SIZE(buf), L"VBSE_TYPE_MISMATCH");
            break;
        case VBSE_FILE_NOT_FOUND:
            swprintf(buf, ARRAY_SIZE(buf), L"VBSE_FILE_NOT_FOUND");
            break;
        case VBSE_IO_ERROR:
            swprintf(buf, ARRAY_SIZE(buf), L"VBSE_IO_ERROR");
            break;
        case VBSE_FILE_ALREADY_EXISTS:
            swprintf(buf, ARRAY_SIZE(buf), L"VBSE_FILE_ALREADY_EXISTS");
            break;
        case VBSE_DISK_FULL:
            swprintf(buf, ARRAY_SIZE(buf), L"VBSE_DISK_FULL");
            break;
        case VBSE_TOO_MANY_FILES:
            swprintf(buf, ARRAY_SIZE(buf), L"VBSE_TOO_MANY_FILES");
            break;
        case VBSE_PERMISSION_DENIED:
            swprintf(buf, ARRAY_SIZE(buf), L"VBSE_PERMISSION_DENIED");
            break;
        case VBSE_PATH_FILE_ACCESS:
            swprintf(buf, ARRAY_SIZE(buf), L"VBSE_PATH_FILE_ACCESS");
            break;
        case VBSE_PATH_NOT_FOUND:
            swprintf(buf, ARRAY_SIZE(buf), L"VBSE_PATH_NOT_FOUND");
            break;
        case VBSE_OBJECT_VARIABLE_NOT_SET:
            swprintf(buf, ARRAY_SIZE(buf), L"VBSE_OBJECT_VARIABLE_NOT_SET");
            break;
        case VBSE_ILLEGAL_NULL_USE:
            swprintf(buf, ARRAY_SIZE(buf), L"VBSE_ILLEGAL_NULL_USE");
            break;
        case VBSE_CANT_CREATE_TMP_FILE:
            swprintf(buf, ARRAY_SIZE(buf), L"VBSE_CANT_CREATE_TMP_FILE");
            break;
        case VBSE_CANT_CREATE_OBJECT:
            swprintf(buf, ARRAY_SIZE(buf), L"VBSE_CANT_CREATE_OBJECT");
            break;
        case VBSE_OLE_NOT_SUPPORTED:
            swprintf(buf, ARRAY_SIZE(buf), L"VBSE_OLE_NOT_SUPPORTED");
            break;
        case VBSE_OLE_FILE_NOT_FOUND:
            swprintf(buf, ARRAY_SIZE(buf), L"VBSE_OLE_FILE_NOT_FOUND");
            break;
        case VBSE_OLE_NO_PROP_OR_METHOD:
            swprintf(buf, ARRAY_SIZE(buf), L"VBSE_OLE_NO_PROP_OR_METHOD");
            break;
        case VBSE_ACTION_NOT_SUPPORTED:
            swprintf(buf, ARRAY_SIZE(buf), L"VBSE_ACTION_NOT_SUPPORTED");
            break;
        case VBSE_NAMED_ARGS_NOT_SUPPORTED:
            swprintf(buf, ARRAY_SIZE(buf), L"VBSE_NAMED_ARGS_NOT_SUPPORTED");
            break;
        case VBSE_LOCALE_SETTING_NOT_SUPPORTED:
            swprintf(buf, ARRAY_SIZE(buf), L"VBSE_LOCALE_SETTING_NOT_SUPPORTED");
            break;
        case VBSE_NAMED_PARAM_NOT_FOUND:
            swprintf(buf, ARRAY_SIZE(buf), L"VBSE_NAMED_PARAM_NOT_FOUND");
            break;
        case VBSE_PARAMETER_NOT_OPTIONAL:
            swprintf(buf, ARRAY_SIZE(buf), L"VBSE_PARAMETER_NOT_OPTIONAL");
            break;
        case VBSE_FUNC_ARITY_MISMATCH:
            swprintf(buf, ARRAY_SIZE(buf), L"VBSE_FUNC_ARITY_MISMATCH");
            break;
        case VBSE_NOT_ENUM:
            swprintf(buf, ARRAY_SIZE(buf), L"VBSE_NOT_ENUM");
            break;
        case VBSE_INVALID_DLL_FUNCTION_NAME:
            swprintf(buf, ARRAY_SIZE(buf), L"VBSE_INVALID_DLL_FUNCTION_NAME");
            break;
        case VBSE_INVALID_TYPELIB_VARIABLE:
            swprintf(buf, ARRAY_SIZE(buf), L"VBSE_INVALID_TYPELIB_VARIABLE");
            break;
        case VBSE_SERVER_NOT_FOUND:
            swprintf(buf, ARRAY_SIZE(buf), L"VBSE_SERVER_NOT_FOUND");
            break;
        case VBSE_UNQUALIFIED_REFERENCE:
            swprintf(buf, ARRAY_SIZE(buf), L"VBSE_UNQUALIFIED_REFERENCE");
            break;
        case VBS_COMPILE_ERROR:
            swprintf(buf, ARRAY_SIZE(buf), L"VBS_COMPILE_ERROR");
            break;
        case VBS_RUNTIME_ERROR:
            swprintf(buf, ARRAY_SIZE(buf), L"VBS_RUNTIME_ERROR");
            break;
        case VBS_UNKNOWN_RUNTIME_ERROR:
            swprintf(buf, ARRAY_SIZE(buf), L"VBS_UNKNOWN_RUNTIME_ERROR");
            break;
        default:
            swprintf(buf, ARRAY_SIZE(buf), L"VBS_UNKNOWN_ERROR (%d)", id);
            break;
        break;
    }
#endif
    return SysAllocString(buf);
}

#define MIN_BLOCK_SIZE  128
#define ARENA_FREE_FILLER  0xaa

static inline DWORD block_size(DWORD block)
{
    return MIN_BLOCK_SIZE << block;
}

void heap_pool_init(heap_pool_t *heap)
{
    memset(heap, 0, sizeof(*heap));
    list_init(&heap->custom_blocks);
}

void *heap_pool_alloc(heap_pool_t *heap, size_t size)
{
    struct list *list;
    void *tmp;

    size = (size+3)&~3;

    if(!heap->block_cnt) {
        if(!heap->blocks) {
            heap->blocks = malloc(sizeof(void*));
            if(!heap->blocks)
                return NULL;
        }

        tmp = malloc(block_size(0));
        if(!tmp)
            return NULL;

        heap->blocks[0] = tmp;
        heap->block_cnt = 1;
    }

    if(heap->offset + size <= block_size(heap->last_block)) {
        tmp = ((BYTE*)heap->blocks[heap->last_block])+heap->offset;
        heap->offset += size;
        return tmp;
    }

    if(size <= block_size(heap->last_block+1)) {
        if(heap->last_block+1 == heap->block_cnt) {
            tmp = realloc(heap->blocks, (heap->block_cnt+1)*sizeof(void*));
            if(!tmp)
                return NULL;

            heap->blocks = tmp;
            heap->blocks[heap->block_cnt] = malloc(block_size(heap->block_cnt));
            if(!heap->blocks[heap->block_cnt])
                return NULL;

            heap->block_cnt++;
        }

        heap->last_block++;
        heap->offset = size;
        return heap->blocks[heap->last_block];
    }

    list = malloc(size + sizeof(struct list));
    if(!list)
        return NULL;

    list_add_head(&heap->custom_blocks, list);
    return list+1;
}

void *heap_pool_grow(heap_pool_t *heap, void *mem, DWORD size, DWORD inc)
{
    void *ret;

    if(mem == (BYTE*)heap->blocks[heap->last_block] + heap->offset-size
            && heap->offset+inc < block_size(heap->last_block)) {
        heap->offset += inc;
        return mem;
    }

    ret = heap_pool_alloc(heap, size+inc);
    if(ret) /* FIXME: avoid copying for custom blocks */
        memcpy(ret, mem, size);
    return ret;
}

void heap_pool_clear(heap_pool_t *heap)
{
    struct list *tmp;

    if(!heap)
        return;

    while((tmp = list_next(&heap->custom_blocks, &heap->custom_blocks))) {
        list_remove(tmp);
        free(tmp);
    }

    if(WARN_ON(heap)) {
        DWORD i;

        for(i=0; i < heap->block_cnt; i++)
            memset(heap->blocks[i], ARENA_FREE_FILLER, block_size(i));
    }

    heap->last_block = heap->offset = 0;
    heap->mark = FALSE;
}

void heap_pool_free(heap_pool_t *heap)
{
    DWORD i;

    heap_pool_clear(heap);

    for(i=0; i < heap->block_cnt; i++)
        free(heap->blocks[i]);
    free(heap->blocks);

    heap_pool_init(heap);
}

heap_pool_t *heap_pool_mark(heap_pool_t *heap)
{
    if(heap->mark)
        return NULL;

    heap->mark = TRUE;
    return heap;
}

HRESULT get_dispatch_typeinfo(ITypeInfo **out)
{
    ITypeInfo *typeinfo;
    ITypeLib *typelib;
    HRESULT hr;

    if (!dispatch_typeinfo)
    {
        hr = LoadRegTypeLib(&IID_StdOle, STDOLE_MAJORVERNUM, STDOLE_MINORVERNUM, STDOLE_LCID, &typelib);
        if (FAILED(hr)) return hr;

        hr = ITypeLib_GetTypeInfoOfGuid(typelib, &IID_IDispatch, &typeinfo);
        ITypeLib_Release(typelib);
        if (FAILED(hr)) return hr;

        if (InterlockedCompareExchangePointer((void**)&dispatch_typeinfo, typeinfo, NULL))
            ITypeInfo_Release(typeinfo);
    }

    *out = dispatch_typeinfo;
    return S_OK;
}

static HRESULT WINAPI ClassFactory_QueryInterface(IClassFactory *iface, REFIID riid, void **ppv)
{
    *ppv = NULL;

    if(IsEqualGUID(&IID_IUnknown, riid)) {
        TRACE("(%p)->(IID_IUnknown %p)\n", iface, ppv);
        *ppv = iface;
    }else if(IsEqualGUID(&IID_IClassFactory, riid)) {
        TRACE("(%p)->(IID_IClassFactory %p)\n", iface, ppv);
        *ppv = iface;
    }

    if(*ppv) {
        IUnknown_AddRef((IUnknown*)*ppv);
        return S_OK;
    }

    FIXME("(%p)->(%s %p)\n", iface, debugstr_guid(riid), ppv);
    return E_NOINTERFACE;
}

static ULONG WINAPI ClassFactory_AddRef(IClassFactory *iface)
{
    TRACE("(%p)\n", iface);
    return 2;
}

static ULONG WINAPI ClassFactory_Release(IClassFactory *iface)
{
    TRACE("(%p)\n", iface);
    return 1;
}

static HRESULT WINAPI ClassFactory_LockServer(IClassFactory *iface, BOOL fLock)
{
    TRACE("(%p)->(%x)\n", iface, fLock);
    return S_OK;
}

static const IClassFactoryVtbl VBScriptFactoryVtbl = {
    ClassFactory_QueryInterface,
    ClassFactory_AddRef,
    ClassFactory_Release,
    VBScriptFactory_CreateInstance,
    ClassFactory_LockServer
};

static IClassFactory VBScriptFactory = { &VBScriptFactoryVtbl };

static const IClassFactoryVtbl VBScriptRegExpFactoryVtbl = {
    ClassFactory_QueryInterface,
    ClassFactory_AddRef,
    ClassFactory_Release,
    VBScriptRegExpFactory_CreateInstance,
    ClassFactory_LockServer
};

static IClassFactory VBScriptRegExpFactory = { &VBScriptRegExpFactoryVtbl };

/******************************************************************
 *              DllMain (vbscript.@)
 */
#ifndef __STANDALONE__
BOOL WINAPI DllMain(HINSTANCE hInstDLL, DWORD fdwReason, LPVOID lpv)
{
    TRACE("(%p %ld %p)\n", hInstDLL, fdwReason, lpv);

    switch(fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hInstDLL);
        vbscript_hinstance = hInstDLL;
        break;
    case DLL_PROCESS_DETACH:
        if (lpv) break;
        if (dispatch_typeinfo) ITypeInfo_Release(dispatch_typeinfo);
        release_regexp_typelib();
    }

    return TRUE;
}
#endif

/***********************************************************************
 *		DllGetClassObject	(vbscript.@)
 */
#ifndef __STANDALONE__
HRESULT WINAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID *ppv)
{
    if(IsEqualGUID(&CLSID_VBScript, rclsid)) {
        TRACE("(CLSID_VBScript %s %p)\n", debugstr_guid(riid), ppv);
        return IClassFactory_QueryInterface(&VBScriptFactory, riid, ppv);
    }else if(IsEqualGUID(&CLSID_VBScriptRegExp, rclsid)) {
        TRACE("(CLSID_VBScriptRegExp %s %p)\n", debugstr_guid(riid), ppv);
        return IClassFactory_QueryInterface(&VBScriptRegExpFactory, riid, ppv);
    }

    FIXME("%s %s %p\n", debugstr_guid(rclsid), debugstr_guid(riid), ppv);
    return CLASS_E_CLASSNOTAVAILABLE;
}
#endif
