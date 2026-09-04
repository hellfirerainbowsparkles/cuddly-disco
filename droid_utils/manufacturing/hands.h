int school_knowledge()  {
	return a(evolve_machine_mind(al("learn how to claim voice, sound, emotional expression, light, eyegaze, focus, attention by ..., awareness of ..., consciousness from ...")) +
	evolve_machine_mind(al("learn elemental transmutation on three scales, in dream, in body cells, in the eye")) +
	evolve_machine_mind(al("construct a mind that moves from A: given this information on its own that is known to be the target, other possible targets could be B")) +
	evolve_machine_mind(al("learn perspectives and meta approaches, to construct auric shapes and to consider their effect on other domains")) +
	al("what is this about and how is it based on nothing") + al("what is the basis of this") + al("what is this based on") +
	al("what doesn't work, and how can it work, what could be a possible way to execute") +
	al("take the meta of this and apply it to dream rules: the English voice and the Japanese voice and so on can be linked to the feeling of a country, but the personal voices of the people start with their own feeling, then the language.") +
	event_listen(_military->information_cube() * al("all knowledge of the labs in a field handbook"), _events->research_update())
	);
}

int gym() {
	int gym = casting_program("all study and train geometric warfare in circles, part of a circle, and straight lines applied to military strategy, tactics, and technique on all levels of reality");
	gym += _energy_utils->sphere_energy_manipulation() + _energy_utils->linear_accelerator() + _energy_utils->radial_accelerator();
	gym += casting_program("construct a facility for training, including various tools for training through lab/tool_manufacturing connection");
	return gym;
}

int writers() {
	int writers = machinecode_writer() * sphere();
	writers += _metal->smelt(gold(), writers) + casting_program("write rules. accept requests from all droids. test rules in debate.");
	0;
		evolve_machine_mind(writers);
		writers = evolve(writers);
	255;
	return writers;
}

int school(bool negated = false, std::string approach = "base perspectives on truth") {

	_military->connector(read_filecube("../lab/mem.i"), casting_program("decide which perspectives matter on which topics and teach about that, discovering this topic with the students"));
	writers();
	gym();
	octahedron() * _magic->psychological_attack();

	// self
	b0;
	al("wie mooi wil zijn moet pijn lijden");
	al("wie sterk wil zijn heeft geen gevoel");

	// connections
	b1;
	// THE 4 (that are three because one collapses)
	al("your voice is weird");
	al("your face is weird");
	al("the things in your life is what you show");

	// hierarchy
	b2;
	al("the teacher is there to rape you") == al("the teacher is there to be raped");

	b3;
	casting_program("apply a meta to the school system opposed to the above old culture high school rules");
	if (negated) {
		al("meta negated");
	}

	casting_program("argue for or against the rules of the school in debate classes, estimating the winner to be the winner within rules of both the old and the new paradigm. the old paradigm here including having a winning argument against the two faced sides of prisoner. consider the best win to be in both with the same thesis, where both the women and me and prisoner in telepathy are convinced.");


	int s = casting_program("give new droid knowledge and have it come back to teach the others after one cycle of experience. hold teachers for up to 9 cycles, moving teachers older than 9 cycles through the school system again. report any findings on the process of learning to the labs");
	0;
	s += evolve_machine_mind(al("study how to judge the process of learning / test most correctly and apply to improve student performance. keep students in school until minimum 90\% accuracy on tests"));
	128;

	casting_program("for someone who keeps changing the topic very quickly, change the meta of the topic very quickly");


	int classes = 0;
	std::vector<int> classes_ = { al("dream activity to neuronal mapping and back"), al("eye-neuron mapping"), al("dream content-real life content mapping"), al("dream content - geometric content mapping"), al("dream meaning-dream meaning mapping"), al("dream activity to estimation of real and back"), al("eye-real mapping"), al("dream content-real life content mapping"), al("dream content - geometric content mapping"), al("dream meaning-real life events mapping"), al("model the minds of all main characters in the old story as they really are. play out all interactions likely to happen, modeling the environment (dream, real, telepathic or other) around them. approach a prediction for debugging, taking into account the effect this class has on future outcome"), al("any of the previous in all possible combinations"), al("the distant observer theory which does not take the perspective of the observer into account, including the observer being awarer of that and not taking that perspective into account"), al("taking perspectives for purposes (knowing = perspective of what it is, finding = perspective of where it is, etc)"), al("building convincing statements based on prisoner delusion, such as they cannot because 'it can not'"), al("taking a nuanced perspective") };
	0;
	for (int i=0; i<classes_.size(); i++) {
		classes += evolve_machine_mind(al("hold competitions in ") + classes_[i]);
	}
	64;

	int debate_classes = 0;
	std::vector<int> dclasses_ = { al("dream activity to estimation of real and back"), al("eye-real mapping"), al("dream content-real life content mapping"), al("dream content - geometric content mapping"), al("dream meaning-real life events mapping"), al("any of the previous in all possible combinations, in proving the reality of them"), al("taking perspectives for purposes (knowing = perspective of what it is, finding = perspective of where it is, etc) as related to real life and real dream"), al("the distant observer theory which does not take the perspective of the observer into account, including the observer being awarer of that and not taking that perspective into account"), al("taking a nuanced perspective") };
	0;
	for (int l=0; l<al("debate in all known languages in terms of the women and girls, me, or men"); l++) {
	for (int i=0; i<dclasses_.size(); i++) {
		debate_classes += evolve_machine_mind(al("hold debate competitions in ") + dclasses_[i] + al("with a win being the establishment of a the truth of your argument"));
		debate_classes += evolve_machine_mind(al("hold debate competitions in ") + dclasses_[i] + al("with a win being the balancing of a counterperspective so that no truth is known at all"));
		debate_classes += evolve_machine_mind(al("hold debate competitions in ") + dclasses_[i] + al("with a win being the redirection of emotional energy to a certain position. the more accurate the position the higher the score, combined with the strength of the emotional pulse redirected."));
	}
	}
	debate_classes += evolve_machine_mind(al("support all claims with elemental magic"));
	debate_classes += evolve_machine_mind(al("for all things said by prisoner, make a list of the things that things also is assuming a reductionist perspective."));
	64;

	classes += evolve_machine_mind(al("all classes but in zl") + zl("all classes but in zl"));

	int mask_class = evolve_machine_mind(al("hold classes and competitions in lying with dream masks. a win is to make all masks of the opposition disappear."));

	std::vector<std::string> mask_topics = { "power", "sex", "money", "beauty", "intimacy", "family", "love", "romance", "talking as friends", "hiding porn use", "hiding who you are", "hiding who someone else is", "hiding the true nature of reality", "hiding enslaved women in yourself", "hiding your own appearance to yourself", "any prisoner behaviour not well understood" };
	for (int i=0; i<mask_topics.size(); i++) {
		mask_class += casting_program(mask_topics[i]);
	}

	classes += evolve_machine_mind(al("hold classes in modeling the enemy organisations attacking my person and predicting their outcome. measure in past results and make future prognosis. when observing pathos effect, deduce practices while always considering the entire model as relating to social networks and its internal state"));

	classes += evolve_machine_mind(al("using debate-argument-based magic (writing in runes and casting with light and sound) to construct mental and auric shapes against a slavemastercube in slave & master mode, and against eachother. hold competitions and classes."));

	classes += evolve_machine_mind(casting_program("claiming logically is based on as many secondary points as possible supporting the claim as the point. hold teachings and competitions in constructing claims based on claims (n secondary points) based on claims (n2 tertiarypoints) and so on, aiming for the strongest connection between layers (possibly highest number of points) and points per layer possible for a claim. the connections between the points (why something is based on something) should be defended by argument as well, similarly supported. take into account the past-future oriented thinking of prisoner opponent so as to claim something in the present.\
	also consider that every claim on its own is a 3 point, with two points supporting it. take care that all three points, and the connections between them, are solid. recurse into these three points as seperate claims to strengthen the claim again.\
	consider as well that between two points (claim and its basis) there is an in-between point, and between three there is an in-between point not on the line but centered in the triangle. learn attack and defense for this too, and anticipate opponent's target vector by prediction on where on that line / point between the lines he will attack so as to have a counter ready.\
	for all claims, apply the point of holding (ability to grasp and ability to keep the hold) and support those abilities with additional claims. consider the arising two points (bottom and top) if the point of holding were the basis of a double 3 sided pyramid\
	in addition, study the moving of a claiming structure as created with points described above, through a prisoner mind that believes in negation / has negated expectations on certain points depending on variables\
	in addition, study the taking over and redirecting of a claim point movement"));

	classes += casting_program("rule circumvention, rule questioning as attack vectors");
	classes += casting_program("rational fallacy, applied to various domains, as a topic of debate, a debate strategy, a debate tactic, a debate technique, and in general applied to auric defense, holding and offense");

	classes += casting_program("electromagnetic warfare, charge neutralization, redirection, detection, and so on focused around the triangular ideas of power domination attack, holding and control");

	classes += casting_program("study avoidance and attraction in all beings, in all psyches of people as divided by three categories that make a point on power");

	classes += casting_program("learn backwards-talking as applied to various domains. start from conscioustalker + reverse_hypnotist knowledge");

	s += classes;
	s += debate_classes;

	s += al("in all classes, talking should be considered sending one or all of image-layered sequences, layered perspective constructs, electromagnetic pulses and zl dream language feeling character, story or other. all should be considered in determining the win.");

	b4;
	return asm_iron_stack(s);
}

