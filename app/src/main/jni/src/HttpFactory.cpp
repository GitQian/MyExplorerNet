#include "HttpFactory.h"
#include "DownloadModule.h"
#include "HttpPostModule.h"
#include "android/log.h"

size_t PostDispose(char *buffer, size_t size, size_t nmemb, void *userdata)
{
    LOGI("result:\n%s\n",buffer);
	return nmemb;
}


void HttpFactory::RequestRegister()
{
HttpPostModule::Init();

HttpPostModule post;
	post.SetTimeOut(60);
//	post.SetHttpHead("Content-Type: application/x-www-form-urlencoded");
	post.SetHttpHead("Content-Type:application/json;charset=UTF-8");
	post.SetWriteFunction(PostDispose);
//	post.SetURL("http://port.365car.com.cn/thirdser/roadRescue/queryRescueMessage");
	post.SetURL("http://api.bigbigcloud.cn/dc/devinfo/v1/device");
//    post.SetPostData("userId=1287812&sign=f44782e8f9adfbc1ae12e70348d6034f");
    post.SetPostData("deviceId=android&appName=xinfo");

	int nRet = post.SendPostRequest();
	if (nRet == 0)
		LOGI("post success!");
	else
		LOGE("post error code:%d", nRet);
}