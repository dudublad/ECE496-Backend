#ifndef AUDIOFILE_H
#define AUDIOFILE_H

#include "audioconfig.h"
#include "RtAudio.h"
#include "QString.h"
#include "stdio.h"
#include "Stk.h"
#include "FileWvIn.h"

int tickFile( void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
 double streamTime, RtAudioStreamStatus status, void *userData );

class AudioFile
{
public:
    AudioFile();
    AudioFile(QString filePath);
    void PlayAudioFile();
    bool isInputOpen();
    void closeFile();
    unsigned int getBufferFrames();

    ~AudioFile();

private:
    std::string filePath;
    unsigned int bufferFrames = stk::RT_BUFFER_SIZE;
    stk::FileWvIn input;
    double rate;

};

#endif // AUDIOFILE_H
