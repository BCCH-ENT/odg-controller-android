//
// Created by Neil Connatty on 2016-11-04.
//

#include "pubnub_interface.h"
#include <android/log.h>


pubnub_interface::pubnub_interface ():
        m_pn(PUBLISH_KEY, SUBSCRIBE_KEY),
        m_helper(),
        m_formatter()
{
    m_pn.set_blocking_io(pubnub::non_blocking);
}

pubnub_interface::~pubnub_interface ()
{
}

void pubnub_interface::on_publish (pubnub::context &pn, pubnub_res res)
{
    if (PNR_OK == res) {
        __android_log_print(ANDROID_LOG_DEBUG, "pubnub_interface::on_publish",
                            "Publish request success: %s", pn.last_publish_result().c_str());
        std::cout << pn.last_publish_result() << std::endl;
    } else {
        __android_log_print(ANDROID_LOG_ERROR, "pubnub_interface::on_publish",
                            "Publish request failed with error code: %d", res);
        __android_log_print(ANDROID_LOG_ERROR, "pubnub_interface::on_publish", "%s", pn.last_publish_result().c_str());
    }
}

void pubnub_interface::publish_input (std::string input)
{
    m_helper.publish(m_pn, m_formatter.format_message(input), INPUT_CHANNEL, pubnub_interface::on_publish);
}

void pubnub_interface::send_message (std::string msg)
{
    m_helper.publish(m_pn, m_formatter.format_message(msg), MSG_CHANNEL, pubnub_interface::on_publish);
}

void pubnub_interface::show_image ()
{
    publish_input("show image");
}

void pubnub_interface::hide_image ()
{
    publish_input("hide image");
}

void pubnub_interface::zoom_image()
{
    publish_input("zoom image");
}

void pubnub_interface::reload_image ()
{
    publish_input("reload image");
}

void pubnub_interface::upload_image ()
{
    publish_input("upload image");
}

void pubnub_interface::scroll_left ()
{
    publish_input("scroll left");
}

void pubnub_interface::scroll_right ()
{
    publish_input("scroll right");
}

void pubnub_interface::flip_view ()
{
    publish_input("flip view");
}

void pubnub_interface::hide_or_show_image ()
{
    publish_input("hide or show image");
}

void pubnub_interface::toggle_function ()
{
    publish_input("toggle function");
}