#include "android/log.h"
#include "curl/curl.h"

//函数声明
typedef size_t (*WriteFunc)(char *ptr, size_t size, size_t nmemb,
		void *userdata);

int init();

bool setURL(const char *strURL);
bool setTimeOut(short usSecond);
bool setHttpHead(const char *strHttpHead);
bool setPostData(const char* strData);
bool setWriteFunction(WriteFunc pFunc);
int sendPostRequest(void);
void cleanup();