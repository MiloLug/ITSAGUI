#pragma once
#define __GUIGL_VIRTUAL_TREE 1
#include <map>
#include <GUIGL/guigl.h>

namespace __GUIGL_VIRTUAL_TREE_SPACE {
	extern std::map<GUI::elemId_t, GUI::Elements::Window*> reg;

	void initVirtualTree();
}