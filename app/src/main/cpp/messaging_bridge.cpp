//
// Created by Neil Connatty on 2016-10-26.
//
#include <jni.h>
#include <android/log.h>
#include <string>
#include "pubnub.hpp"
#include "pubnub_interface.h"

extern "C"
{
    pubnub_interface* pn_interface = 0;
    jobject j_messenger;
    JavaVM* java_vm;

    jint JNI_OnLoad (JavaVM * vm, void* reserved)
    {
        java_vm = vm;
        return JNI_VERSION_1_6;
    }

    void Java_com_bcch_neilconnatty_odgcontroller_MainActivity_sendMessage (JNIEnv* env, jobject thisObj, jstring msg)
    {
        const char *cMsg = env->GetStringUTFChars(msg, NULL);
        if (cMsg == NULL)
            __android_log_print(ANDROID_LOG_ERROR, "sendMessage", "error converting jstring to cstring");

        std::string message(cMsg);
        pn_interface->send_message(message);
        delete(cMsg);
    }

    void Java_com_bcch_neilconnatty_odgcontroller_MainActivity_showImage (JNIEnv* env, jobject)
    {
        pn_interface->show_image();
    }

    void Java_com_bcch_neilconnatty_odgcontroller_MainActivity_hideImage (JNIEnv* env, jobject)
    {
        pn_interface->hide_image();
    }

    void Java_com_bcch_neilconnatty_odgcontroller_MainActivity_zoomImage (JNIEnv* env, jobject)
    {
        pn_interface->zoom_image();
    }

    void Java_com_bcch_neilconnatty_odgcontroller_MainActivity_reloadImage (JNIEnv* env, jobject)
    {
        pn_interface->reload_image();
    }

    void Java_com_bcch_neilconnatty_odgcontroller_MainActivity_uploadImage (JNIEnv* env, jobject)
    {
        pn_interface->upload_image();
    }

    void Java_com_bcch_neilconnatty_odgcontroller_MainActivity_scrollLeft (JNIEnv* env, jobject)
    {
        pn_interface->scroll_left();
    }

    void Java_com_bcch_neilconnatty_odgcontroller_MainActivity_scrollRight (JNIEnv* env, jobject)
    {
        pn_interface->scroll_right();
    }

    void Java_com_bcch_neilconnatty_odgcontroller_MainActivity_flipView (JNIEnv* env, jobject)
    {
        pn_interface->flip_view();
    }

/** return false on unsuccessful initialize */
    int Java_com_bcch_neilconnatty_odgcontroller_MainActivity_initializeMessenger
            (JNIEnv* env, jobject callingObject)
    {
        j_messenger = env->NewGlobalRef(callingObject);

        pn_interface = new pubnub_interface();
        if (!pn_interface) {
            __android_log_print(ANDROID_LOG_ERROR, "initializeMessenger",
                                "error creating pubnub interface");
            return 0;
        }

        return 1;
    }

    void Java_com_bcch_neilconnatty_odgcontroller_MainActivity_stopMessenger
            (JNIEnv* env, jobject)
    {
        delete pn_interface;
    }
}