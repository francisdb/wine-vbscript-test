//
// Created by Francis De Brabandere on 13/02/2025.
//

#ifndef SCRIPTSITE_H
#define SCRIPTSITE_H

#include <activscp.h>

// Define the IActiveScriptSite structure
typedef struct {
    IActiveScriptSite IActiveScriptSite_iface;
    ULONG ref;
} ScriptSite;

ScriptSite *CreateScriptSite();

#endif //SCRIPTSITE_H
