extern "C"
{
#include "x86_64-linux-gnu/libavcodec/avcodec.h"
#include "x86_64-linux-gnu/libavformat/avformat.h"
}

#include <string>
#include <iostream>
#include <vector>


int main() {
    av_register_all();

    AVFormatContext *pFormatCtx = nullptr;
    std::string inputFile = "/home/danek/Downloads/videoplayback.mp4";
    if (avformat_open_input(&pFormatCtx, inputFile.c_str(), NULL, 0) != 0) {
        //CloseFile();
        return false;
    }
// Get infromation about streams
    if (avformat_find_stream_info(pFormatCtx, NULL) < 0) {
        //  CloseFile();
        return false;
    }
    //av_dump_format(pFormatCtx, 0,  inputFile.c_str(), 0);


    std::cout << pFormatCtx->nb_streams << std::endl;
    std::cout << pFormatCtx->nb_streams << std::endl;

    std::vector<AVStream *> streams;
    for (auto i = 0u; i < pFormatCtx->nb_streams; i++)
        streams.push_back(pFormatCtx->streams[i]);


    AVPacket *packet;
    AVFormatContext *c = nullptr;
    for (auto it : streams) {
        int ret;
        if (it->codec->coder_type == AVMEDIA_TYPE_VIDEO) {
            do {
                ret = av_read_frame(pFormatCtx, packet);
                av_write_frame(c, packet);

            } while (ret == 1);

        }
    }

//    av_dump_format()


}