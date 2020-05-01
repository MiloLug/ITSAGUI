#include "Element.h"
//#include "../Event.h"
#include "../common.h"
//#include "../Draw.h"
//#include "Window.h"
//#include "ElementsStore.h"
#include "Container.h"
#include <iostream>

namespace GUI {
	namespace Elements {
//base type info =========================
		const std::type_info* Element::__base_type = &typeid(Element);
		const std::type_info* Element::__current_type() {
			return &typeid(Element);
		}
//attributes =========================
		std::string& Element::title() {
			return this->_title;
		};
		Element* Element::title(const std::string& title) {
			this->_title = title;
			//this->windowRedraw(); //?
			return this;
		};

//data =========================

//constructor =========================
		Element::Element() {
			std::cout << "el created" << std::endl;
			//this->style = new Style(this);
		}

//some methods =========================
		void Element::__drawBase(int wwidth, int wheight) {}

		//?
		/*Element* Element::windowReviewZ() {
			Window* w = (Window*)ElementsStore::getElement(this->parentWindow, this->parentWindow);
			if (w != nullptr)
				w->__reviewZ = true;
			return this;
		}
		Element* Element::windowRedraw() {
			Window* w = (Window*)ElementsStore::getElement(this->parentWindow, this->parentWindow);
			if (w != nullptr)
				w->__redraw = true;
			return this;
		}*/

		Element* Element::hide() {
			return this;
		}
		Element* Element::show() {
			return this;
		}

		/*Element* Element::emit(const elemId_t& eventId, Event::baseEvent* e) {
			Event::emit(this->parentWindow, this->id, eventId, e);
			return this;
		};
		Element* Element::emit(const elemId_t& eventId, void* e) {
			Event::emit(this->parentWindow, this->id, eventId, e);
			return this;
		};

		Element* Element::on(const elemId_t& eventId, const Event::defaultELFn& fn, void* additionData, Event::defaultELFn*& listenerPtr) {
			Event::on(this->parentWindow, this->id, eventId, fn, additionData, listenerPtr);
			return this;
		};
		Element* Element::on(const elemId_t& eventId, const Event::defaultELFn& fn, void* additionData) {
			Event::on(this->parentWindow, this->id, eventId, fn, additionData);
			return this;
		};
		Element* Element::on(const elemId_t& eventId, const Event::defaultELFn& fn, Event::defaultELFn*& listenerPtr) {
			Event::on(this->parentWindow, this->id, eventId, fn, listenerPtr);
			return this;
		};
		Element* Element::on(const elemId_t& eventId, const Event::defaultELFn& fn) {
			Event::on(this->parentWindow, this->id, eventId, fn);
			return this;
		};

		Element* Element::off(const elemId_t& eventId, const Event::defaultELFn& fn) {
			Event::off(this->parentWindow, this->id, eventId, fn);
			return this;
		};
		Element* Element::off(const elemId_t& eventId, Event::defaultELFn* fn) {
			Event::off(this->parentWindow, this->id, eventId, fn);
			return this;
		};

		Element* Element::emit(const std::string& eventId, Event::baseEvent* e) {
			Event::emit(this->parentWindow, this->id, strHash(eventId.data()), e);
			return this;
		};
		Element* Element::emit(const std::string& eventId, void* e) {
			Event::emit(this->parentWindow, this->id, strHash(eventId.data()), e);
			return this;
		};

		Element* Element::on(const std::string& eventId, const Event::defaultELFn& fn, void* additionData, Event::defaultELFn*& listenerPtr) {
			Event::on(this->parentWindow, this->id, strHash(eventId.data()), fn, additionData, listenerPtr);
			return this;
		};
		Element* Element::on(const std::string& eventId, const Event::defaultELFn& fn, void* additionData) {
			Event::on(this->parentWindow, this->id, strHash(eventId.data()), fn, additionData);
			return this;
		};
		Element* Element::on(const std::string& eventId, const Event::defaultELFn& fn, Event::defaultELFn*& listenerPtr) {
			Event::on(this->parentWindow, this->id, strHash(eventId.data()), fn, listenerPtr);
			return this;
		};
		Element* Element::on(const std::string& eventId, const Event::defaultELFn& fn) {
			Event::on(this->parentWindow, this->id, strHash(eventId.data()), fn);
			return this;
		};

		Element* Element::off(const std::string& eventId, const Event::defaultELFn& fn) {
			Event::off(this->parentWindow, this->id, strHash(eventId.data()), fn);
			return this;
		};
		Element* Element::off(const std::string& eventId, Event::defaultELFn* fn) {
			Event::off(this->parentWindow, this->id, strHash(eventId.data()), fn);
			return this;
		};*/

		inline Element* Element::__linkContainer(Container* cont) {
			this->containers.insert(cont);
			return this;
		};
		inline Element* Element::__unlinkContainer(Container* cont) {
			this->containers.erase(cont);
			return this;
		};
		inline size_t Element::__containersCount() {
			return this->containers.size();
		};

		void Element::removeSelf() {
			
			std::cout << "el removed" << std::endl;

			std::unordered_set<Container*>::iterator iter = this->containers.begin();
			Container* tmp;
			while (iter != this->containers.end()) {
				tmp = *iter;
				iter = this->containers.erase(iter);
				tmp->unlinkElement(this);
			}
			delete this;
		}
		Element::~Element() {
			//delete this->style;
		}
	}
}