#ifndef AUDIOSINE_H
#define AUDIOSINE_H

#include "SineWave.h"
#include "QString"
#include "stdio.h"
#include "RtAudio.h"
#include "audioconfig.h"
#include "FileWvOut.h"

int tickSine( void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
         double streamTime, RtAudioStreamStatus status, void *dataPointer );

class audioSine
{
public:
    audioSine();
    audioSine(float durationSecs, QString filePath, unsigned int freq);
    void setFrequency(float freq);
    void setFilePath(QString filePath);
    void playSine();
    void generateSine();

private:
    unsigned int sineWaveFrequency = 400;
    stk::SineWave sineWave;
    unsigned int bufferFrames = stk::RT_BUFFER_SIZE;
    std::string filePath;
    stk::FileWvOut output;
    float durationSecs = 0.1;
};

#endif // AUDIOSINE_H
