#include "com_xinzhihui_myexplorernet_MainActivity.h"
#include <jni.h>
#include "DownloadModule.h"
#include "HttpPostModule.h"
#include "JNIUtil.h"

class HttpFactory
{
public:
    static void RequestRegister();
};