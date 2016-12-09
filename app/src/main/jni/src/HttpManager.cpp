#include "HttpManager.h"
#include "sha1/sha1.h"

size_t CallBack(char *buffer, size_t size, size_t nmemb, void *userdata)
{
    __android_log_print(ANDROID_LOG_INFO,"qiansheng","result:\n%s\n",buffer);
}
/******************** 获取SHA1字符串 *****************/
char* getSha1Str(const char* str)
{
    char *result = (char *)malloc(sizeof(char) * 20);

    SHA1Context sha;
    SHA1Reset(&sha);
    int i;

    SHA1Input(&sha, (const unsigned char *) str, strlen(str));
    if (!SHA1Result(&sha))
    {
        fprintf(stderr, "ERROR-- could not compute message digest\n");
    }else
    {
        char *point = result;
             for(i = 0; i < 5 ; i++)
             {
                 __android_log_print(ANDROID_LOG_INFO,"qiansheng", "SHA1:%X ", sha.Message_Digest[i]);
                 sprintf(point, "%X", sha.Message_Digest[i]);
                 for(;*point;) point++;
//                 sprintf(buff,"0x%x",sha.Message_Digest[i]);
             }
        __android_log_print(ANDROID_LOG_INFO,"qiansheng", "REsult:%s", result);
    }
    return result;
}

/***************** 注册接口 ****************************/
void dataRegister(NetItem *netItem)
{

    init();
    setTimeOut(netItem->vidPid);
    setURL("http://api.bigbigcloud.cn/dc/devinfo/v1/device");
    setHttpHead("Content-Type:application/json;charset=UTF-8");
    setHttpHead("Auth-Signature:d52b1da6a6d91085d2879bd14d98ba3e77112e9d");
    setHttpHead("Auth-AppId:10678706631");
    setHttpHead("Auth-Timestamp:1481252077");
//    setHttpHead(strHead);aleLanguage:null,localeRegion:null,);
    setWriteFunction(CallBack);
//    setPostData(strData);
    setPostData("{\"deviceId\":\"0c0c078c519041040000741000000000\",\"deviceGuid\":\"0c0c078c519041040000741000000000\",\"uploadType\":\"0\",\"appName\":\"net_speedup\",\"appVersion\":\"00.00.02\",\"clientIp\":null,\"longitude\":null,\"latitude\":null,\"localTime\":null,\"extData\":\"realtek:rtl8723bu\",\"product\":{\"deviceSerial\":\"7410519041040c0c078c\",\"deviceName\":\"t3_p3\",\"wifiId\":\"other\",\"wifiModel\":\"rtl8723bu\",\"hostModel\":\"sun8iw11p1\",\"chipType\":null,\"platformType\":null,\"deviceVendor\":null,\"deviceModel\":null,\"productName\":null,\"brand\":null,\"brand2\":null,\"resolution\":null,\"localeLanguage\":null,\"localeRegion\":null,\"manufacturer\":null,\"odmName\":null},\"system\":{\"os\":null,\"osVersion\":null,\"kernelVersion\":null},\"phoneInfo\":{\"iemi\":null,\"imsi\":null,\"carrier\":null,\"access\":null,\"accessSubtype\":null},\"property\":{\"ro.data\":null}}");
    sendPostRequest();
    cleanup();
//    return true;
}