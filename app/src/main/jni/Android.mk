
LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)  
LOCAL_MODULE := curl  
LOCAL_SRC_FILES := lib/$(TARGET_ARCH_ABI)/libcurl.so
include $(PREBUILT_SHARED_LIBRARY) 

include $(CLEAR_VARS)
LOCAL_C_INCLUDES := $(LOCAL_PATH)/include
LOCAL_MODULE := curlTest
LOCAL_SRC_FILES := src/HttpModel.cpp \
    src/HttpManager.cpp \
    sha1/sha1.c \
    src/cJson.c \
    src/Make.cpp

LOCAL_SHARED_LIBRARIES := curl
LOCAL_LDLIBS := -llog
include $(BUILD_SHARED_LIBRARY)

