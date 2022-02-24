#include "audiosine.h"

audioSine::audioSine() : currentId(++id)
{
}

void audioSine::setFrequency(float freq){
    this->sineWave.setFrequency(freq);
}

void audioSine::setDuration(float len){
    this->durationSecs = len;
}

void audioSine::setFilePath(QString filePath){
    this->filePath = filePath.toStdString() + std::to_string(this->currentId);
}

void audioSine::generateSine(){
    const int numSamples = this->durationSecs * stk::Stk::sampleRate();

    this->output.openFile(this->filePath, 1, stk::FileWrite::FILE_WAV, stk::Stk::STK_SINT16);

    this->sineWave.reset();

    for (int i = 0; i < numSamples; i++){
        output.tick(this->sineWave.tick());
    }

    this->output.closeFile();
}
