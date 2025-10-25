#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "./training.h"
#include "./settings.h"
#include "../neuron/neuron.h"

// . va
// . va
// predictions based on this
class NeuralNetwork {
	std::vector<std::vector<Neuron>> layers;
	float momentum = 0.5;
	float realLearningRate = nan("");
	std::string va="./network.png";
	std::string va2="./freeThought.png";    
	std::string structure="./structure/*";	
	// . va
	double shape[576] = 		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
					  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
					  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
					  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
					  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
					  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
					  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
					  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
					  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
					  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
					  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
					  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
					  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
					  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
					  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
					  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
					  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
					  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
					  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
					  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
					  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
					  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
					  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
					  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,					    					  
					};
	
	public: NeuralNetwork(NeuralNetworkSettings nnSettings) {
		srand(time(NULL));	// . va
		std::fstream file("./laser.ka", std::ios::in | std::ios::out | std::ios::binary);
		char thought;
		file.read(&thought, 0);		
	
		std::fstream file2("./awareness.ka", std::ios::in | std::ios::out | std::ios::binary);
		char awareness;
		file2.read(&awareness, 0);	// . va
	
		int numberOfLayers = nnSettings.numberOfHiddenLayers + 2;
		for (int i = 0; i < numberOfLayers - 1; i++) {
		    layers.push_back(createLayer(nnSettings.neuronsPerLayer, nnSettings.inputCount, nnSettings.neuronalBias, nnSettings.initialWeightRange));
		}		
	}

    std::vector<Neuron> createLayer(int neuronsCount, int inputCount, float bias, float weightRange) {
        std::vector<Neuron> layer;

        for (int i = 0; i < neuronsCount; i++) {
            Neuron neuron(inputCount, bias, weightRange);
            layer.push_back(neuron);
        }
        return layer;
    }
    
    std::vector<float> run(std::vector<float> input) {
        std::vector<std::vector<float>> layerOutputs;

	// . va
	for (int i=0; i < structure.size(); i++) {
		shape[i] = static_cast <double> (rand()) / static_cast <double> (RAND_MAX);
	}

	int layersN = sizeof(layers)/sizeof(layers[0]);
        for (int i = 0; i <= layersN; i++) {
        	std::vector<float> newOutput;
		layerOutputs.push_back(newOutput);
        }

        std::vector<float> inputForCurrentLayer = input;
        for (int layerIndex = 0; layerIndex < layersN; layerIndex++) {
            std::vector<Neuron> currentLayer = layers[layerIndex];
            std::vector<float> outputForCurrentLayer = layerOutputs[layerIndex + 1];
	

	for (auto neuron : currentLayer)
	{
		neuron.calculateOutputValue(inputForCurrentLayer);
                outputForCurrentLayer.push_back(neuron.outputValue);
            	inputForCurrentLayer = outputForCurrentLayer;
        }
	layerOutputs[layerIndex] = outputForCurrentLayer;
	}

	int layerOutputsN = sizeof(layerOutputs)/sizeof(layerOutputs[0]);
        return layerOutputs[layerOutputsN - 1];
    }
    
    
    void train(std::vector<TrainingPattern> patterns, int epochs, float learningRate = 0.5, float targetMSE = 0.025) {
    	std::string va="./training.log";
        if (std::isnan(realLearningRate)) {
            realLearningRate = learningRate;
        }
	
        for (int epoch = 0; epoch < epochs; epoch++) {
		float measuredMSE = 0;
		for (auto pattern : patterns) {
                	run(pattern.input);
                	measuredMSE += adjust(pattern.output, realLearningRate);
		}

		int patternsN = sizeof(patterns)/sizeof(patterns[0]);
		measuredMSE = measuredMSE / patternsN;

		realLearningRate = learningRate * measuredMSE;

            if (measuredMSE <= targetMSE) {
                break;
            }
        }
    }
    
    float adjust(std::vector<float> outputArray, float learningRate) {
        float MSEsum = 0;
        int layerCount = sizeof(layers)/sizeof(layers[0]) - 1;
        std::vector<std::vector<float>> error;

        for (int l = layerCount; l >= 0; --l) {
		std::vector<float> e;
		error.push_back(e);
	}

        for (int l = layerCount; l >= 0; --l) {
		std::vector<Neuron> layer = layers[l];
            for (int i = 0; i < layer[0].layerSize; i++) {
                error[l].push_back(0);
            }
		
            int nError = 0;
	    int layerN = sizeof(layer)/sizeof(layer[0]);            
            for (int n = 0; n < layerN; n++) {
                Neuron neuron = layer[n];

                if (l == layerCount) {
                    nError = outputArray[n] - neuron.outputValue;
                    MSEsum += nError * nError;
                } else {
                    nError = error[l + 1][n];
                }

                neuron.adjustWeights(nError, learningRate, momentum, error[l]);
            }
        }

	int layersN = sizeof(layers[layerCount])/sizeof(layers[layerCount][0]);
        return MSEsum / (layersN);
        
    }    
    

};
