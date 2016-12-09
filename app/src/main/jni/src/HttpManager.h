#include "HttpModel.h"

#ifndef ANDROID_RIL_SERVICE_INTERFACE_H
#define ANDROID_RIL_SERVICE_INTERFACE_H

#ifdef __cplusplus
extern "C" {
#endif

#define BUFFER_LEN 128
typedef struct
{
	unsigned int vidPid;
	char operatorName[BUFFER_LEN];
	char latitude[BUFFER_LEN];
	char longitude[BUFFER_LEN];
	char sysMode[BUFFER_LEN];
}NetItem;

extern char* getSha1Str(const char* str);

extern void dataRegister(NetItem *netItem);


#ifdef __cplusplus
}
#endif

#endif //ANDROID_RIL_SERVICE_INTERFACE_H