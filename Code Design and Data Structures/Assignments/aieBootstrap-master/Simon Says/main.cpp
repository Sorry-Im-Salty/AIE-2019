#include "Simon_SaysApp.h"

int main() {
	
	// allocation
	auto app = new Simon_SaysApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}