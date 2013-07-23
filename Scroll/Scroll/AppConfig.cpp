/////////////////////////////////////////
//
// pocode application configuration
//
/////////////////////////////////////////


#include "poApplication.h"
#include "ScrollApp.h"

poObject *createObjectForID(uint uid) {
	return new ScrollApp();
}

void setupApplication() {
	applicationCreateWindow(0, WINDOW_TYPE_NORMAL, "Scroll", 100, 100, 800, 600);
}

void cleanupApplication() {
}