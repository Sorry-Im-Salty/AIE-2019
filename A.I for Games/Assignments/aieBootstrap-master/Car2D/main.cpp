#include "Application2D.h"

int main() {
	
	// allocation
	auto app = new Application2D();

	// initialise and loop
	app->run("Car2D", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}