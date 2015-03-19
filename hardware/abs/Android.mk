LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SRC_FILES:= abs_test.c
LOCAL_MODULE_TAGS := optional
LOCAL_SHARED_LIBRARIES += libabs
LOCAL_MODULE := abs_test
include $(BUILD_EXECUTABLE)


include $(CLEAR_VARS)
LOCAL_SRC_FILES:= libabs.c
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE := libabs
include $(BUILD_SHARED_LIBRARY)
