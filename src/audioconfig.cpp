#include "audioconfig.h"

AudioConfig::AudioConfig()
{
    this->streamParameters.deviceId = this->dac.getDefaultInputDevice();
    this->streamParameters.nChannels = 1;
    this->audioFormat = (sizeof(stk::StkFloat) == 8) ? RTAUDIO_FLOAT64 : RTAUDIO_FLOAT32;

    stk::Stk::setSampleRate(this->stkFrequency);
}

bool AudioConfig::isPlaying(){
    return this->dac.isStreamOpen();
}

void AudioConfig::closeStream(){
    if (this->isPlaying()){
        this->dac.closeStream();
    }
}

void AudioConfig::startStream(){
    this->dac.startStream();
}

RtAudio::StreamParameters* AudioConfig::getStreamParams(){
    return &this->streamParameters;
}

RtAudioFormat AudioConfig::getAudioFormat(){
    return this->audioFormat;
}

AudioConfig audio;
