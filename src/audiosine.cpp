#include "audiosine.h"

audioSine::audioSine()
{
    this->sineWave = stk::SineWave();
}

audioSine::audioSine(float durationSecs, QString filePath, unsigned int freq){
    this->sineWave = stk::SineWave();
    this->durationSecs = durationSecs;
    this->filePath = filePath.toStdString();
    this->sineWaveFrequency = freq;
}

void audioSine::playSine(){
    audio.closeStream();

    this->setFrequency(this->sineWaveFrequency);

    try {
        audio.dac.openStream(audio.getStreamParams(), NULL, audio.getAudioFormat(),
                             (unsigned int) stk::Stk::sampleRate(), &this->bufferFrames,
                             &tickSine, (void *)&this->sineWave);
    }  catch (RtAudioError &error) {
        error.printMessage();
    }

    audio.startStream();
}

void audioSine::setFrequency(float freq){
    this->sineWaveFrequency = freq;
    this->sineWave.setFrequency(freq);
}

void audioSine::setFilePath(QString filePath){
    this->filePath = filePath.toStdString();
}

void audioSine::generateSine(){
    const int numSamples = this->durationSecs * stk::Stk::sampleRate();

    this->output.openFile(this->filePath, 1, stk::FileWrite::FILE_WAV, stk::Stk::STK_SINT16);

    this->sineWave.reset();
    this->setFrequency(this->sineWaveFrequency);

    for (int i = 0; i < numSamples; i++){
        output.tick(this->sineWave.tick());
    }

    this->output.closeFile();

}

int tickSine( void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
         double streamTime, RtAudioStreamStatus status, void *dataPointer )
{
    stk::SineWave *sine = (stk::SineWave *) dataPointer;
    auto *samples = (stk::StkFloat *) outputBuffer;
    for ( unsigned int i=0; i<nBufferFrames; i++ ){
        try {
            *samples++ = sine->tick();
        } catch (stk::StkError &error) {
            error.printMessage();
        }
    }
    return 0;
}
