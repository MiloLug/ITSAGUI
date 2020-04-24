#pragma once
#ifndef __ELEMENTS_WINDOW

#define __ELEMENTS_WINDOW

#include "../defs.h"
#include <string>
#include <functional>

#include "../GLFW/SysWindow.h"
#include "ElementContainer.h"
#include "Element.h"

namespace GUI {
	namespace Elements {
		class Window : public ElementContainer {
		public:
			static const std::type_info* __base_type;
			const std::type_info* __current_type;

			bool __redraw = true;
			bool __reviewZ = true;

			bool nativeResizing = false;
			SysWindow* sysWindow = nullptr;

			Window(elemId_t id);
			Window(const Window& win) = delete;
			Window(const Window* win) = delete;
			virtual void __drawBase(int wwidth, int wheight);

			static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
			static void cursorPosCallback(GLFWwindow* window, double xpos, double ypos);
			static void cursorEnterCallback(GLFWwindow* window, int entered);
			static void closeCallback(GLFWwindow* window);
			static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

			virtual void removeSelf();
			virtual ~Window();
		};
	}
}

#endif