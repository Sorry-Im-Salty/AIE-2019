#include "Application2D.h"

int main() {
	
	// allocation
	auto app = new Application2D();

	// initialise and loop
	app->run("Tank2D", 840, 650, false);

	// deallocation
	delete app;

	return 0;
}