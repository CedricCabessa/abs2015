#include "libabs.h"
#include "utils/Log.h"

#include <jni.h>

static void ThrowAbsException(JNIEnv *env, const char *message) {
  jclass class = (*env)->FindClass(env, "android/abs/AbsException");
  if (class != NULL) {
    (*env)->ThrowNew(env, class, message);
  }
  (*env)->DeleteLocalRef(env, class);
}

static void jni_abs_clear(JNIEnv *env, jclass cls)
{
    abs_clear();
}


static jstring jni_abs_getData(JNIEnv *env, jclass cls)
{
    char buff[1024];
    int ret = abs_getdata(buff, 1024);
    if (ret < 0) {
        ThrowAbsException(env, "fail to get data");
    }
    return (*env)->NewStringUTF(env, buff);

}

static void jni_abs_putData(JNIEnv *env, jclass cls, jstring string)
{
    int ret;
    const char *buff = (*env)->GetStringUTFChars(env, string, NULL);
    int length = (*env)->GetStringLength(env, string);
    ret = abs_putdata(buff, length);
    if (ret < 0) {
        ThrowAbsException(env, "fail to put data");
    }
    (*env)->ReleaseStringUTFChars(env, string, buff);
}

static const JNINativeMethod gMethods[] = {
    { "clear",    "()V", jni_abs_clear },
    { "getData",  "()Ljava/lang/String;", jni_abs_getData },
    { "putData",  "(Ljava/lang/String;)V", jni_abs_putData },
};

jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    jclass clazz;
    JNIEnv* env = NULL;
    const char* const kClassName = "android/abs/Abs";

    if ((*vm)->GetEnv(vm, (void**) &env, JNI_VERSION_1_4) != JNI_OK) {
        ALOGE("cannot get env");
        return -1;
    }

    clazz = (*env)->FindClass(env, kClassName);
    if (clazz == NULL) {
        ALOGE("cannot find class %s", kClassName);
        return -1;
    }

    if ((*env)->RegisterNatives(env, clazz, gMethods,
                                sizeof(gMethods) / sizeof(gMethods[0])) != JNI_OK)  {
        ALOGE("cannot register");
        return -1;
    }

    return JNI_VERSION_1_4;
}
