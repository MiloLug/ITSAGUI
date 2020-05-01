#include "Window.h"
#include "../Draw.h"
#include "../Event.h"


namespace GUI {
	namespace Elements {
//base type info =========================
		const std::type_info* Window::__base_type = &typeid(Window);
		const std::type_info* Window::__current_type() {
			return &typeid(Window);
		}
//attributes =========================

//data =========================
		inline Window* Window::parentWindow() {
			return this;
		}
		inline Element* Window::parent() {
			return nullptr;
		}
		inline Element* Window::parentWindow(Window* w) {
			return this;
		}
		inline Element* Window::parent(Element* el) {
			return this;
		}
//constructor =========================
		Window::Window() : ElementContainer() {
			this->sysWindow = new SysWindow(100, 100, "");
			this->sysWindow->setUserPointer(this);

			this->sysWindow->framebufferSizeCallback(Window::framebufferSizeCallback);
			this->sysWindow->cursorPosCallback(Window::cursorPosCallback);
			this->sysWindow->cursorEnterCallback(Window::cursorEnterCallback);
			this->sysWindow->closeCallback(Window::closeCallback);
			this->sysWindow->mouseButtonCallback(Window::mouseButtonCallback);
		}

//some methods =========================
		void Window::__drawBase(int wwidth, int wheight) {
			/*if (!this->nativeResizing) {
				glfwSetWindowSize(this->sysWindow->instance, this->style->_width, this->style->_height);
			}
			else
				this->nativeResizing = false;
			glfwSetWindowTitle(this->sysWindow->instance, this->_title.data());
			glClearColor(this->style->_background[0], this->style->_background[1], this->style->_background[2], this->style->_background[3]);
			glClear(GL_COLOR_BUFFER_BIT);*/
		}

		void Window::framebufferSizeCallback(GLFWwindow* window, int width, int height) {
			/*Window* _this = (Window*)glfwGetWindowUserPointer(window);
			Event::baseEvent* tmp = new Event::framebufferSizeEvent(width, height);
			tmp->window = _this->id;
			Event::emit(__EVENT_FRAMEBUFFER_SIZE, tmp);
			Event::execAll();

			_this->nativeResizing = true;
			_this->style->_width = width;
			_this->style->_height = height;
			_this->__redraw = true;

			Draw::draw();*/
		}
		void Window::cursorPosCallback(GLFWwindow* window, double xpos, double ypos) {
			/*Window* _this = (Window*)glfwGetWindowUserPointer(window);
			Event::baseEvent* tmp = new Event::mouseMoveEvent(xpos, ypos);
			tmp->window = _this->id;
			tmp->eventId = EVENT_MOUSE_MOVE;
			Event::emit(__EVENT_MOUSE_MOVE, tmp);*/
		}
		void Window::closeCallback(GLFWwindow* window) {
			/*Window* _this = (Window*)glfwGetWindowUserPointer(window);
			Event::baseEvent* tmp = new Event::closeEvent();
			tmp->window = _this->id;
			Event::emit(__EVENT_CLOSE, tmp);*/
		}
		void Window::cursorEnterCallback(GLFWwindow* window, int entered) {
			/*Window* _this = (Window*)glfwGetWindowUserPointer(window);
			Event::baseEvent* tmp;
			if (entered) {
				tmp = new Event::windowMouseEnterEvent();
				tmp->window = _this->id;
				Event::emit(__EVENT_WINDOW_MOUSE_ENTER, tmp);
			}
			else {
				tmp = new Event::windowMouseLeaveEvent();
				tmp->window = _this->id;
				Event::emit(__EVENT_WINDOW_MOUSE_LEAVE, tmp);
			}*/
		};
		void Window::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
			/*Window* _this = (Window*)glfwGetWindowUserPointer(window);
			double xpos, ypos;
			glfwGetCursorPos(window, &xpos, &ypos);

			Event::mouseButtonEvent* tmp = new Event::mouseButtonEvent(xpos,ypos, button);
			tmp->window = _this->id;

			if (action == GLFW_PRESS)
				tmp->eventId = EVENT_MOUSE_DOWN;
			else
				tmp->eventId = EVENT_MOUSE_UP;

			Event::emit(__EVENT_MOUSE_MOVE, tmp);*/
		}

		void Window::removeSelf() {
			this->removeAll();
			delete this;
		}
		Window::~Window() {
			delete this->sysWindow;
		}
	}
}