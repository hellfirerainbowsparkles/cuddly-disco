

class DroidBase() {

	public: DroidBase() {
		activate_droid_dependencies();

		cube() * iron() * _material->copper() * _material->smart_plasma();
	}
}
