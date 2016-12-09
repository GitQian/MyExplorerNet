#include <jni.h>
#include "android/log.h"
#include "curl/curl.h"
#include "HttpModel.h"

CURL *m_pCurl;

//初始化
int init()
{
m_pCurl = curl_easy_init();
curl_easy_setopt(m_pCurl, CURLOPT_NOSIGNAL, 1L);
if(m_pCurl) {
    __android_log_print(ANDROID_LOG_INFO,"qiansheng","Curl init:Success!");
}
}

//设置URL
bool setURL(const char *strURL)
{
	if (m_pCurl == NULL)
		return false;
	int nRet = curl_easy_setopt(m_pCurl, CURLOPT_URL, strURL);
	if (nRet == CURLE_OK)
	{
	    __android_log_print(ANDROID_LOG_INFO,"qiansheng","setURL:Success!!!\n");
		return true;
	}
	else
	{
	    __android_log_print(ANDROID_LOG_ERROR,"qiansheng","setURL:Failed!!!\n");
		return false;
	}
}

//设置超时
bool setTimeOut(short usSecond)
{
	if (m_pCurl == NULL)
		return false;
	int nRet = curl_easy_setopt(m_pCurl, CURLOPT_TIMEOUT, usSecond);
	if (nRet == CURLE_OK)
	{
	    __android_log_print(ANDROID_LOG_INFO,"qiansheng","setTimeOut:Success!!!\n");
		return true;
	}
	else
	{
	    __android_log_print(ANDROID_LOG_ERROR,"qiansheng","setTimeOut:Failed!!!\n");
		return false;
	}
}

curl_slist *plist = NULL;
//设置头部Header
bool setHttpHead(const char *strHttpHead)
{
	if (m_pCurl == NULL)
		return false;
	plist = curl_slist_append(plist, strHttpHead);
	int nRet = curl_easy_setopt(m_pCurl, CURLOPT_HTTPHEADER, plist);
	if (nRet == CURLE_OK)
		return true;
	else
	{
		return false;
	}
}

//设置post Data键值对
bool setPostData(const char* strData)
{
int nRet = curl_easy_setopt(m_pCurl, CURLOPT_POSTFIELDS, strData);
if (nRet == CURLE_OK)
		return true;
	else
	{
		return false;
	}
}

//设置回调函数
bool setWriteFunction(WriteFunc pFunc)
{
	if (m_pCurl == NULL)
		return false;
	curl_easy_setopt(m_pCurl, CURLOPT_WRITEDATA, NULL);
	int nRet = curl_easy_setopt(m_pCurl, CURLOPT_WRITEFUNCTION, pFunc);
	if (nRet == CURLE_OK)
		return true;
	else
	{
		return false;
	}
}

//发送请求
int sendPostRequest(void)
{
	if (m_pCurl == NULL)
		return -1;
	int nRet = curl_easy_perform(m_pCurl);
	if (nRet == CURLE_OK)
		return 0;
	else
	{
		return nRet;
	}
}

void cleanup()
{
	curl_easy_cleanup(m_pCurl);
}