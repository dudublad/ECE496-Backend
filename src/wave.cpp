#include "wave.h"
#include <math.h>
#include <iostream>

//Constructors
wave::wave(){
    //TODO: How to set default values for a class
}
wave::wave(double amplitude_in, double frequency_in,
           double phase_in, double duration_in, std::string type_in){
    std::cout << "entered constructor" << std::endl;
    amplitude = amplitude_in;
    frequency = frequency_in;
    phase = phase_in;
    duration = duration_in;
    type = type_in;
    values = NULL;

    std::cout << "pre generate" << std::endl;
    generate();
    std::cout << "post generate" << std::endl;
}

wave::~wave(){
    //TODO: verify that this is all that is needed
    delete[] values;
}

//Setters
void wave::setAmplitude(double amplitude_in){
    //limit?
    amplitude = amplitude_in;
}
void wave::setFrequency(double freqeuncy_in){
    frequency = freqeuncy_in;
}
void wave::setPhase(double phase_in){
    phase = phase_in;
}
void wave::setDuration(double duration_in){
    //limit?
    duration = duration_in;
}
void wave::setType(std::string type_in){
    if(type_in == "sin" || type_in == "square" || type_in == "saw") type = type_in;
    if(type_in == "sawtooth") type = "saw";
}

//Generators
void wave::generate(){
    //Clear previous values
    std::cout << "before values clearing" << std::endl;
    if(values != NULL) delete[] values;
    std::cout << "skipped deletion" << std::endl;

    //TODO: fix #define so this can use fSampling
    double size = duration * 44100;
    values = new double[size];
    std::cout << "allocated space" << std::endl;

    //Generate based on wave type
    if(type == "sin"){
        std::cout << "generating sin" << std::endl;
        generateSin(size);
    }
    else if (type == "square"){
        generateSquare(size);
    }
    else if (type == "saw"){
        generateSawtooth(size);
    }
    else{
        return;
    }
}

void wave::generateSin(double size){
    std::cout << "entered generate sin" << std::endl;
    for(int i = 0; i < size; i++){
        //TODO: M_PI is not working here for some reason idk
        values[i] = amplitude*sin((2*3.141592653589793238462643383279502884
                                   *frequency*0.00002267573*i) + phase);
        std::cout << values[i] << std::endl;
    }
}

void wave::generateSquare(double size){
    for(int i = 0; i < size; i++){
        //TODO: M_PI is not working here for some reason idk
        double temp = sin((2*3.141592653589793238462643383279502884
                                   *frequency*0.00002267573*i) + phase);
        temp > 0 ? values[i] = amplitude : values[i] = amplitude *-1;
    }
}

//TODO: generate sawtooth wave
void wave::generateSawtooth(double size){
    for(int i = 0; i < size; i++){
        values[i] = 0.1;
    }
}
