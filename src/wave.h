#define fSampling = 44100;
#define tSampling = 0.00002267573;

#ifndef WAVE_H
#define WAVE_H

#include <string>
#include <math.h>
#include <cmath>

class wave
{       
    private:
        double frequency;
        double amplitude;
        double phase;
        double duration;
        std::string type;
        //TODO: make values private & accessible w a function

    public:
    //Constructors
        wave();
        wave(double amplitude_in, double frequency_in,
             double phase_in, double duration_in, std::string type_in);
        ~wave();
     //TEMP!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        double* values;
    //Set private values
        void setFrequency(double frequency);
        void setAmplitude(double amplitude);
        void setPhase(double phase);
        void setDuration(double duration);
        void setType(std::string type);
    //Generate Wave Functions
        void generate();
        void generateSin(double size);
        void generateSquare(double size);
        void generateSawtooth(double size);
};

#endif // WAVE_H
