#include "audiofile.h"

AudioFile::AudioFile()
{
    this->input = stk::FileWvIn();
}

AudioFile::AudioFile(QString filePath){
    this->input = stk::FileWvIn();
    this->filePath = filePath.toStdString();

    try{
        this->input.openFile(this->filePath);
    } catch (stk::StkError &error) {
        error.printMessage();
    }

    this->rate = this->input.getFileRate() / stk::Stk::sampleRate();
    this->input.setRate(this->rate);
}

void AudioFile::PlayAudioFile(){
    audio.closeStream();

    try {
        this->input.openFile(this->filePath);
    }  catch (stk::StkError &error) {
        error.printMessage();
    }

    try {
        audio.dac.openStream(audio.getStreamParams(), NULL, audio.getAudioFormat(),
                             (unsigned int) stk::Stk::sampleRate(), &this->bufferFrames, &tickFile, (void*)&this->input);
    }  catch (RtAudioError &error) {
        error.printMessage();
    }

    audio.startStream();
}

bool AudioFile::isInputOpen(){
    return this->input.isOpen();
}

void AudioFile::closeFile(){
    if (this->isInputOpen()){
        this->input.closeFile();
    }
}

unsigned int AudioFile::getBufferFrames(){
    return this->bufferFrames;
}

AudioFile::~AudioFile(){
    this->closeFile();
}

int tickFile( void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
         double streamTime, RtAudioStreamStatus status, void *userData )
{
    stk::FileWvIn *input = (stk::FileWvIn *) userData;
    auto *samples = (stk::StkFloat *) outputBuffer;
    for ( unsigned int i=0; i<nBufferFrames; i++ ){
        try {
            *samples++ = input->tick();
        }  catch (stk::StkError &error) {
            error.printMessage();
        }
    }
    return 0;
}

