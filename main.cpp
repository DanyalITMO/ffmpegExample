extern "C"
{
#include "x86_64-linux-gnu/libavcodec/avcodec.h"
#include "x86_64-linux-gnu/libavformat/avformat.h"
}

#include <string>

int main()
{
    av_register_all();

    AVFormatContext* pFormatCtx = nullptr;
    std::string inputFile = "/home/danek/Downloads/videoplayback.mp4";
    if (avformat_open_input(&pFormatCtx, inputFile.c_str(), NULL, 0) != 0)
    {
        //CloseFile();
        return false;
    }
// Get infromation about streams
    if (avformat_find_stream_info(pFormatCtx, NULL) < 0)
    {
      //  CloseFile();
        return false;
    }
    av_dump_format(pFormatCtx, 0,  inputFile.c_str(), 0);


    //---
    int i;
    AVCodecContext *pCodecCtxOrig = NULL;
    AVCodecContext *pCodecCtx = NULL;

// Find the first video stream
    int videoStream=-1;
    for(i=0; i<pFormatCtx->nb_streams; i++)
        if(pFormatCtx->streams[i]->codec->codec_type==AVMEDIA_TYPE_VIDEO) {
            videoStream=i;
            break;
        }
    if(videoStream==-1)
        return -1; // Didn't find a video stream

// Get a pointer to the codec context for the video stream
    pCodecCtx=pFormatCtx->streams[videoStream]->codec;

    //----


    AVCodec *pCodec = nullptr;

// Find the decoder for the video stream
    pCodec=avcodec_find_decoder(pCodecCtx->codec_id);
    if(pCodec==NULL) {
        fprintf(stderr, "Unsupported codec!\n");
        return -1; // Codec not found
    }
// Copy context
    pCodecCtx = avcodec_alloc_context3(pCodec);

    if(avcodec_copy_context(pCodecCtx, pCodecCtxOrig) != 0) {
        fprintf(stderr, "Couldn't copy codec context");
        return -1; // Error copying codec context
    }
// Open codec
    if(avcodec_open2(pCodecCtx, pCodec, nullptr)<0)
        return -1; // Could not open codec
}