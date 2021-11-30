#include "WaveGenerator.h"

WaveGenerator::WaveGenerator(WaveType type, float freq, size_t numSamples) {
    data.resize(numSamples);
}

WaveGenerator::~WaveGenerator() {

}

void WaveGenerator::setFrequency(float freq) {

}

void WaveGenerator::setWaveType(WaveType type) {

}

void WaveGenerator::generate() {
    if(type == WaveType_Sine) {
        for(int i = 0; i < numSamples; i++){
            data[i] = sineWave.tick();
        }
    }
    else {
        //TODO: Add support for other wavetypes
        for(int i = 0; i < numSamples; i++){
            data[i] = 0;
        }
    }
}
