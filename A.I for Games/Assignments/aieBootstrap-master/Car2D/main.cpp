#include "Car2DApp.h"

int main() {
	
	// allocation
	auto app = new Car2DApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}