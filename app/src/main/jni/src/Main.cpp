#include "com_xinzhihui_myexplorernet_MainActivity.h"
#include <jni.h>
#include "HttpFactory.h"
#include "DownloadModule.h"
#include "HttpPostModule.h"
#include "JNIUtil.h"
extern "C"
{
jobject g_objAc = NULL;
JNIEXPORT void JNICALL Java_com_xinzhihui_myexplorernet_MainActivity_TestDownload(JNIEnv* env,
		jobject obj)
{
	DownLoadModule download;
	const char* url =
			"http://s3.amazonaws.com/hum9-lwg8-qa2w/PsiphonAndroid.apk";
	int nRet = download.DownLoad(url, "/sdcard/Download", "PsiphonAndroid.apk");
	if (nRet == 0)
		LOGI("download success!");
	else
		LOGE("download error code:%d", nRet);
}
size_t PostDispose(char *buffer, size_t size, size_t nmemb, void *userdata)
{
	JNIUtil util;
	jobject jdata = util.String2Jstring(buffer);
	JNIEnv* env = util.GetJNIEnv();
	jclass cMainActivity = env->GetObjectClass(g_objAc);
	jmethodID methodPostDispose = env->GetMethodID(cMainActivity, "postDispose",
			"(Ljava/lang/String;)V");
	env->CallVoidMethod(g_objAc, methodPostDispose, jdata);
	return nmemb;
}
JNIEXPORT void JNICALL Java_com_xinzhihui_myexplorernet_MainActivity_TestHttpPost(JNIEnv* env,
		jobject obj)
{
//	HttpPostModule post;
//	post.SetTimeOut(60);
////	post.SetHttpHead("Content-Type: application/x-www-form-urlencoded");
//	post.SetHttpHead("Content-Type:application/json;charset=UTF-8");
//	post.SetWriteFunction(PostDispose);
////	post.SetURL("http://port.365car.com.cn/thirdser/roadRescue/queryRescueMessage");
//	post.SetURL("http://api.bigbigcloud.cn/dc/devinfo/v1/device");
////    post.SetPostData("userId=1287812&sign=f44782e8f9adfbc1ae12e70348d6034f");
//    post.SetPostData("deviceId=android&appName=xinfo");
//
//	int nRet = post.SendPostRequest();
//	if (nRet == 0)
//		LOGI("post success!");
//	else
//		LOGE("post error code:%d", nRet);

HttpFactory::RequestRegister();
}
JNIEXPORT void JNICALL Java_com_xinzhihui_myexplorernet_MainActivity_Init(JNIEnv* env, jobject obj)
{
	HttpPostModule::Init();
	JavaVM* vm;
	env->GetJavaVM(&vm);
	JNIUtil::Init(env);
	g_objAc = env->NewGlobalRef(obj);
}
JNIEXPORT void JNICALL Java_com_xinzhihui_myexplorernet_MainActivity_Cleanup(JNIEnv* env, jobject obj)
{
	HttpPostModule::Cleanup();
	env->DeleteGlobalRef(g_objAc);
	g_objAc = NULL;
	JNIUtil::CleanUp(env);
}
}

