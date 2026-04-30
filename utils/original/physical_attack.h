int physical_attack() {

	int core = f_small(casting_program("a thing is a thing and an idea is an idea and a dream thing is a dream thing")) + casting_program("the feeling of rejection by the mother, on all scales of dream") +
	casting_program("the knowing of the power of a woman in the rejection of an applicant");

	int existential_core = cube() * water() * casting_program("the illusion of choice when there isn't any from a larger perspective") +
	casting_program("the feeling of the mask outside of not being guilty combined with the feeling inside of knowing that you are guilty") +
	casting_program("how you were constructed by the machine and how much you are identified with that constructed identity in relation to your own personal freedom") +
	casting_program("the pain your feel when being selfaware");


	int death_pyramid = f_small(casting_program("the feeling, seeing, and thinking about your own physical death") * plane(3) + spark()) + f_small(casting_program("the feeling, seeing, and thinking about your father's physical death") * plane(3) + spark(), 2) + f_small(casting_program("the feeling, seeing, and thinking about your father's father's physical death") * plane(3) + spark()) * _colours->black();
	int attack = f_small(core, 2) + f_small(existential_core) + death_pyramid;
	int power_pyramid = plane(3) + al("personal power") + al("financial power") + al("mental power") + spark();
	int attack_pyramid = a(pyramid(3) * al("psychological content of the attack")) + f_small(power_pyramid);

	int avoiding = random_n(0, 1);
	if (avoiding == 1) {
		return pyramid() * casting_program("based on the avoidance of the pyramid of physical_attack(), they do not want to experience that, so then they need to experience something less bad instead so they agree. but then it's the psychological attack") + a(connection() + octahedron(attack_pyramid) * water() * air()) + psychological_attack();
	}

	return attack_pyramid + sphere(machine_eye() + al("take a topdown perspective on the prisoner, seeing in him the attack_pyramid content"));
}
