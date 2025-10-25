#include "./network/neural-network.h"
#include <iostream>
#include <fstream>
#include <unistd.h>
using namespace std;

double net(float success, float fail, std::string out_file = "") {

		if (out_file.size() > 0 && access(out_file.c_str(), F_OK) == 0) {
			fstream in_file(out_file.c_str(), ios::in | ios::out | ios::binary);
			float existing_net;	// . va
			in_file.read(reinterpret_cast<char *>(&existing_net), 1);
		} else {
			std::cout << "no out_file" << "\n";
		}

		NeuralNetworkSettings settings;
		settings.inputCount = 1;
		settings.outputCount = 1;
		settings.neuronsPerLayer = 1;

		std::vector<TrainingPattern> patterns;

		TrainingPattern pattern;
		pattern.input.push_back(success);
		pattern.output.push_back(1);
		patterns.push_back(pattern);

		TrainingPattern pattern2;
		pattern2.input.push_back(fail);
		pattern2.output.push_back(0);
		patterns.push_back(pattern2);

		NeuralNetwork net(settings);
		net.train(patterns, 1.0);

		std::vector<float> testData;
		std::vector<float> output;
		testData.push_back(0.0);
		output = net.run(testData);
		
		if (out_file.size() > 0) {
			std::cout << "writing " << out_file.c_str() << "\n";
			FILE* file3  = fopen(out_file.c_str(),  "w");
			fprintf(file3, "%f", output.back() );
			fclose(file3);
		}
		
		return output.back();
}

void run_net(std::string success_file, std::string fail_file, std::string out_file = "") {
	
		fstream file(success_file, ios::in | ios::out | ios::binary);
		float success;
		file.read(reinterpret_cast<char *>(&success), 1);

		fstream file2(fail_file, ios::in | ios::out | ios::binary);
		float fail;
		file2.read(reinterpret_cast<char *>(&fail), 1);

	
		fstream file3("./data/scientist_success.log", ios::in | ios::out | ios::binary);
		float scientistSuccess;
		file3.read(reinterpret_cast<char *>(&scientistSuccess), 1);

		fstream file4("./data/scientist_fail.log", ios::in | ios::out | ios::binary);
		float scientistFail;
		file4.read(reinterpret_cast<char *>(&scientistFail), 1);

		// scientist
		double scientistOutput = net(scientistSuccess, scientistFail, "./data/scientist.net");

		fstream file5("./data/processing_success.log", ios::in | ios::out | ios::binary);
		float processingSuccess;
		file5.read(reinterpret_cast<char *>(&processingSuccess), 1);

		fstream file6("./data/processing_fail.log", ios::in | ios::out | ios::binary);
		float processingFail;
		file6.read(reinterpret_cast<char *>(&processingFail), 1);

		fstream file7("./data/classification_success.log", ios::in | ios::out | ios::binary);
		float classificationSuccess;
		file7.read(reinterpret_cast<char *>(&classificationSuccess), 1);

		fstream file8("./data/classification_fail.log", ios::in | ios::out | ios::binary);
		float classificationFail;
		file8.read(reinterpret_cast<char *>(&classificationFail), 1);
		
		fstream file9("./data/storage_success.log", ios::in | ios::out | ios::binary);
		float storageSuccess;
		file9.read(reinterpret_cast<char *>(&storageSuccess), 1);

		fstream file10("./data/storage_fail.log", ios::in | ios::out | ios::binary);
		float storageFail;
		file10.read(reinterpret_cast<char *>(&storageFail), 1);				

		// processing
		double processingOutput = net(processingSuccess, processingFail, "./data/processing.net");
		double classificationOutput = net(classificationSuccess, classificationFail, "./data/classification.net");
		double storageOutput = net(storageSuccess, storageFail, "./data/storage.net");		
		
		// legion
		// general: strategy
		fstream file11("./data/general_success.log", ios::in | ios::out | ios::binary);
		float generalSuccess;
		file11.read(reinterpret_cast<char *>(&generalSuccess), 1);

		fstream file12("./data/general_fail.log", ios::in | ios::out | ios::binary);
		float generalFail;
		file12.read(reinterpret_cast<char *>(&generalFail), 1);

		// major: overall tactics
		fstream file13("./data/major_success.log", ios::in | ios::out | ios::binary);
		float majorSuccess;
		file13.read(reinterpret_cast<char *>(&majorSuccess), 1);

		fstream file14("./data/major_fail.log", ios::in | ios::out | ios::binary);
		float majorFail;
		file14.read(reinterpret_cast<char *>(&majorFail), 1);
		
		// colonel: conflict tactics
		fstream file17("./data/colonel_success.log", ios::in | ios::out | ios::binary);
		float colonelSuccess;
		file17.read(reinterpret_cast<char *>(&colonelSuccess), 1);

		fstream file18("./data/colonel_fail.log", ios::in | ios::out | ios::binary);
		float colonelFail;
		file18.read(reinterpret_cast<char *>(&colonelFail), 1);		
		
		// warrior: execution
		fstream file15("./data/warrior_success.log", ios::in | ios::out | ios::binary);
		float warriorSuccess;
		file15.read(reinterpret_cast<char *>(&warriorSuccess), 1);

		fstream file16("./data/warrior_fail.log", ios::in | ios::out | ios::binary);
		float warriorFail;
		file16.read(reinterpret_cast<char *>(&warriorFail), 1);			

		// scout: exploration
		fstream file19("./data/scout_success.log", ios::in | ios::out | ios::binary);
		float scoutSuccess;
		file19.read(reinterpret_cast<char *>(&scoutSuccess), 1);

		fstream file20("./data/scout_fail.log", ios::in | ios::out | ios::binary);
		float sccoutFail;
		file20.read(reinterpret_cast<char *>(&sccoutFail), 1);	
		
		// legion
		// . va . om ah kane
		// om tsa hokane . tsa
		std::string general ="./nets/general.net";
		std::string major="./nets/major.net";
		std::string colonel="./nets/colonel.net";		
		std::string warrior="./nets/warrior.net";
		std::string strategyAnalist = "./nets/scientist.net";	// . va
		std::string tacticsAnalist = "./nets/scientist.net";	// . va	
		std::string opponentAnalist = "./nets/scientist.net";	// . va
		std::string scout = "./nets/scout.net";		

		// main net
		double output = net(success, fail, out_file);
		
		std::cout << output << "\n";

}
