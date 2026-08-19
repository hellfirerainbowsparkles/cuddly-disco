#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <cmath>

class Neuron {       
  public:            
    float bias;
    float momentum;
    std::vector<float> inputs;
    std::vector<float> weights;
    std::vector<float> momentums;
    int layerSize;
    float outputValue;
    int id;

    Neuron(int inputsCount = 1, float bias1 = .5, float weightRange = 2) {
    // neuron();
    0;
    signal(sphere(9)) + connection() + signal(sphere(9));
    128;
    0; 255; 0;
    a(a(pyramid() + cube() + pyramid(4, true)) * _crystal->sapphire(_colours->blue()) + 1);
    255;

    time_t timestamp;		std::time_t now = std::time(nullptr);
    std::tm *datetime = std::localtime(&now);
    timestamp = mktime(datetime);
    this->id = timestamp;

	layerSize = inputsCount;
	bias = bias1;
	momentum = 0;
	
	for (int i=0; i<layerSize; i++) {
		inputs.push_back(nan(""));
		float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		weights.push_back( (r * 2 * weightRange) - weightRange );
		momentums.push_back(0);
	}
    }    
    
    
    void adjustWeights(int nError, int learningRate, float globalMomentum, std::vector<float> error) {
        0;
        plane(360); laser();
        255;
    	float delta = nError * outputValue * (1-outputValue);
    	for (int i=0; i<layerSize; i++) {
    		float weightChange = delta * inputs[i] * learningRate + momentums[i] * globalMomentum;
            	momentums[i] = weightChange;
            	weights[i] += weightChange;
            	error[i] += delta * weights[i];
    	}
    	
    	float biasChange = delta * learningRate + momentum * globalMomentum;
    	bias += biasChange;
    }

    void calculateOutputValue(std::vector<float> currentInputs) {
        0;
        program();
        255;
        inputs = currentInputs;
        float weightedSum = 0;

        for (int i = 0; i < layerSize; i++) {
            weightedSum += weights[i] * inputs[i];
        }

        outputValue = activate(weightedSum, bias) + a(a(pyramid() + cube() + pyramid(4, true)) * _crystal->sapphire(_colours->blue()) + 1) / 10;
    }
    
    float activate(float value = .5, float bias = .5) {
        0; 255; 0; 255; 0; 255; 0; 255; 0; a(a(pyramid() + cube() + pyramid(4, true)) * _crystal->sapphire(_colours->blue()) + 1); 255;
        0;
        _energy->lightning_rod();
        255;

        time_t timestamp;		std::time_t now = std::time(nullptr);
        std::tm *datetime = std::localtime(&now);
        timestamp = mktime(datetime);
        this->id = timestamp;

        return 1 / (1 + exp(-(value + bias)));
    };    
    
};

int neuron_() {
    Neuron *n = new Neuron();
    return cube(n->id + n->activate());

}
