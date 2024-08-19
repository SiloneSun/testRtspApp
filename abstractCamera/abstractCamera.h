#ifndef __ABSTRACT_CAMERA__
#define __ABSTRACT_CAMERA__

#include <iostream>
#include <map>


struct STREAM_INFO
{
    std::uint32_t width;
    std::uint32_t height;
    std::uint32_t format;
    std::uint32_t fps;
    std::uint32_t bitrate;
    std::uint32_t gop;
    std::uint32_t rcmode;
};

struct FRAME
{
    void* data;
    std::uint32_t length;
};



class AbstractCamera
{
public:
    AbstractCamera();
    ~AbstractCamera();

public:
    /* Basic Function */
    std::int32_t open_device();
    std::int32_t close_device();
    std::int32_t stream_on();
    std::int32_t stream_off();
    std::int32_t set_stream_info(STREAM_INFO& info);
    std::int32_t get_stream_info(STREAM_INFO& info);
    std::uint32_t read_frame(FRAME& frame);

private:
    /* inner memeber values */
    void* pCamera; //嵌入到实际项目中后，这个地方改用具体的项目Camera实例
    std::uint32_t m_cur_camera_id;
    std::map<std::uint32_t, STREAM_INFO> m_stream_info_map;

private:
    /* inner member functions */
};

#endif