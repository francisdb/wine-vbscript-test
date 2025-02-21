//
// Created by Francis De Brabandere on 13/02/2025.
//

#ifndef SCRIPTSITE_H
#define SCRIPTSITE_H

#include <activscp.h>

typedef struct {
    SCODE scode;
} LastErrorInfo;

// Define the IActiveScriptSite structure
typedef struct {
    IActiveScriptSite IActiveScriptSite_iface;
    ULONG ref;
} ScriptSite;

ScriptSite *CreateScriptSite();

const LastErrorInfo* GetLastErrorInfo();
void ClearErrorInfo();

#endif //SCRIPTSITE_H
