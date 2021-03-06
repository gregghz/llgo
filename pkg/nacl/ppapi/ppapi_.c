// Copyright 2013 The llgo Authors.
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file.

// +build pnacl

#include <ppapi/c/ppp.h>
#include <ppapi/c/ppp_instance.h>

#include <string.h>

PP_Bool ppapi_instanceDidCreate(PP_Instance instance,
                                uint32_t argc,
                                const char* argn[],
                                const char* argv[]);
void ppapi_instanceDidDestroy(PP_Instance instance);
void ppapi_instanceDidChangeView(PP_Instance instance, PP_Resource view);
void ppapi_instanceDidChangeFocus(PP_Instance instance, PP_Bool has_focus);
PP_Bool ppapi_instanceHandleDocumentLoad(PP_Instance instance, PP_Resource url_loader);

struct PPP_Instance_1_1 instance = {
    &ppapi_instanceDidCreate,
    &ppapi_instanceDidDestroy,
    &ppapi_instanceDidChangeView,
    &ppapi_instanceDidChangeFocus,
    &ppapi_instanceHandleDocumentLoad
};

void PPP_ShutdownModule()
{
	// We must define this to link with ppapi.
}

const void* PPP_GetInterface(const char *name)
{
    if (strcmp(name, PPP_INSTANCE_INTERFACE_1_1) == 0)
        return &instance;
    return NULL;
}

