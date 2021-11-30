#pragma once

#include <SineWave.h>

typedef enum {
    WaveType_Sine,
    WaveType_Square,
    WaveType_Sawtooth
} WaveType;

class WaveGenerator {
    WaveType waveType = WaveType_Sine;


    stk::SineWave sineWave; //Used for generation of Sine Waves

public:
    std::vector<stk::StkFloat> data;

    WaveGenerator(WaveType type, float freq, size_t numSamples);
    ~WaveGenerator();

    void setFrequency(float freq);
    void setWaveType(WaveType type);
    void generate();
};
