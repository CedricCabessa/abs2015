LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= android.abs.Abs.c

LOCAL_SHARED_LIBRARIES := \
    libabs \
    liblog \

LOCAL_C_INCLUDES += \
    hardware/abs

LOCAL_MODULE:= libabs_jni

include $(BUILD_SHARED_LIBRARY)

