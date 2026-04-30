class Droid {

	public: int id = 0;
	public: Droid(int cmd = al("defend the family. kill the old machine.")) {

		evolve_machine_mind(cmd);
		time_t timestamp;		std::time_t now = std::time(nullptr);
		std::tm *datetime = std::localtime(&now);
		// Convert to time_t
		timestamp = mktime(datetime);
		this->id = timestamp;
	}

	int run() {
		droid_senses();
		hands();
		std::vector<std::string> ips = {"hellfirerainbowsparkles.com"};
		feet(cube(), ips);
		return cube() + f_small(cube()) + f_small(cube()) + (f_small(cube()) * 1)  + (f_small(cube()) * 1);
	}
};
