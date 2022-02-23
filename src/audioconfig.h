#ifndef AUDIOCONFIG_H
#define AUDIOCONFIG_H

#include <RtAudio.h>
#include <Stk.h>
#include <FileWvIn.h>
#include "SineWave.h"

class AudioConfig
{
public:
    AudioConfig();
    bool isPlaying();
    void closeStream();
    void startStream();
    RtAudio::StreamParameters* getStreamParams();
    RtAudioFormat getAudioFormat();
    RtAudio dac; // digital to analogue converter

private:
     //RtAudio API variables
    RtAudio::StreamParameters streamParameters;
    RtAudioFormat audioFormat;

    const float stkFrequency = 44100.0;
};

extern AudioConfig audio;

#endif // AUDIOCONFIG_H
