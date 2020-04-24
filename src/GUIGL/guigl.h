#pragma once
#ifndef __GUIGL

#define __GUIGL

#include "defs.h"
#include "glall.h"
#include "Elements/Elements.h"
#include "Event.h"
#include "Draw.h"
#include "strHash.h"
#include "functionCompare.h"
#include "GL/VAO.h"
#include "GLFW/SysWindow.h"

namespace GUI {
	extern bool glfwInitialized;

	void init();
	//void openWindow(const char* id);
	void runLoop();
	void terminate();
}

#endif