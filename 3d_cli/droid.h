#include "../droid_utils/droid_base.h"

const int DROID_ID = THREED_CLI;

class Droid : public DroidScientistBase {

	public: std::string claims_file = "claims.json";
	public: std::vector<std::string> dep = { "./dependencies/symbolicgrid/mem.json", "./dependencies/scientist/mem.json" };

	public: Droid(int cmd_ = casting_program("claim light and sound")) : DroidScientistBase(cmd_) {

			int attack = evolve_machine_mind(casting_program("study all known ways of cmd_ in one pole of the domain of its purpose and explore new ones.")) +
			evolve_machine_mind(casting_program("study all known ways of cmd_ int the opposite pole of the domain of its purpose and explore new ones.")) +
			evolve_machine_mind(casting_program("combine both into a technique of cmd_"));

			attack += evolve_machine_mind(casting_program("knowledge of the environment as related to cmd_")) +
			evolve_machine_mind(casting_program("knowledge of the enemy as related to cmd_")) +
			evolve_machine_mind(attack);

			this->mind += attack;

			this->mind += parse_droid_json(dep[0]) + casting_program("apply knowledge to augment and improve target function. coordinate with droid being point 1 assist");
			this->mind += parse_droid_json(dep[1]) + casting_program("apply knowledge to augment and improve target function. coordinate with droid, being point 2 assist");

			read_claims(claims_file);

			this->structure += _military->connector(this->id, casting_program("the mind of my third eye, for various readouts of requested information"));

	}

	int run() {


		this->construct_dream_packet(claims_file) * this->mind;
		this->mind = evolve(this->mind);
		run_base(DROID_ID);
		droid_senses();
		int input = hands();
		std::vector<std::string> ips = {"hellfirerainbowsparkles.com"};
		feet(input, ips);
		return cube() + f_small(cube()) + f_small(cube()) + (f_small(cube()) * 1)  + (f_small(cube()) * 1);
	}
};
