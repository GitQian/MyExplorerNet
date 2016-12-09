#include "com_xinzhihui_myexplorernet_MainActivity.h"
//#include "HttpModel.h"
#include "sha1.h"
#include "HttpManager.h"
#include <jni.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#define TESTA   "abc"

size_t PostDispose(char *buffer, size_t size, size_t nmemb, void *userdata)
{
    __android_log_print(ANDROID_LOG_INFO,"qiansheng","result:\n%s\n",buffer);
}

JNIEXPORT void JNICALL Java_com_xinzhihui_myexplorernet_MainActivity_TestDownload(JNIEnv* env,
		jobject obj)
{

}



JNIEXPORT void JNICALL Java_com_xinzhihui_myexplorernet_MainActivity_TestHttpPost(JNIEnv* env,
		jobject obj)
{
//    //第一次请求
//    init();
//    setTimeOut(100);
//    setURL("http://api.bigbigcloud.cn/dc/devinfo/v1/device");
//    setHttpHead("Content-Type:application/json;charset=UTF-8");
//    setPostData("deviceId=android&appName=xinfo");
//    setWriteFunction(PostDispose);
//    sendPostRequest();
//    cleanup();
//
//    //第二次请求
//    init();
//    setURL("http://api.bigbigcloud.cn/dc/devinfo/v1/device");
//    setWriteFunction(PostDispose);
//    sendPostRequest();
NetItem item = {60, "http://api.bigbigcloud.cn/dc/devinfo/v1/device", "Content-Type:application/json;charset=UTF-8", "qian", "sheng"};
NetItem *netItem = &item;
dataRegister(netItem);
//requestRegister("http://api.bigbigcloud.cn/dc/devinfo/v1/device", "Content-Type:application/json;charset=UTF-8", "deviceId=android&appName=xinfo");

getSha1Str(TESTA);
}


JNIEXPORT void JNICALL Java_com_xinzhihui_myexplorernet_MainActivity_Init(JNIEnv* env, jobject obj)
{


}

JNIEXPORT void JNICALL Java_com_xinzhihui_myexplorernet_MainActivity_Cleanup(JNIEnv* env, jobject obj)
{


}

#ifdef __cplusplus
}
#endif