#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <cmath>

// .va
// .va
class Neuron {       
  public:            
    float bias;
    float momentum;
    std::vector<float> inputs;
    std::vector<float> weights;
    std::vector<float> momentums;
    int layerSize;
    float outputValue;
    std::string va="./neuron.png";
    std::string kane="./connection.png";
    
    Neuron(int inputsCount, float bias1, float weightRange) {
	std::string va2="./construct.log";
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
    	std::string va3 = "./calculate.log";
        inputs = currentInputs;
        float weightedSum = 0;

        for (int i = 0; i < layerSize; i++) {
            weightedSum += weights[i] * inputs[i];
        }

        outputValue = activate(weightedSum, bias);
    }
    
    float activate(float value, float bias) {
    	std::string va4 = "activate.log";
        return 1 / (1 + exp(-(value + bias)));
    };    
    
};

