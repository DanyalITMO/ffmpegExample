extern "C"
{
#include "x86_64-linux-gnu/libavcodec/avcodec.h"
#include "x86_64-linux-gnu/libavformat/avformat.h"
}

#include <string>

int main()
{
    av_register_all();

    AVFormatContext* pFormatCtx;
    std::string fn = "";
    if (av_open_input_file(&pFormatCtx, inputFile.c_str(), NULL, 0, NULL) != 0)
    {
        CloseFile();
        return false;
    }
// Get infromation about streams
    if (avformat_find_stream_info(pFormatCtx, NULL) < 0)
    {
        CloseFile();
        return false;
    }
}