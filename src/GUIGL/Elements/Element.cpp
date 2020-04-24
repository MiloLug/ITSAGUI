#include "Element.h"
#include "../Event.h"
#include "../strHash.h"
#include "../Draw.h"
#include "Window.h"
#include "ElementsStore.h"
#include "Style.h"

namespace GUI {
	namespace Elements {
		const std::type_info* Element::__base_type = &typeid(Element);

		std::string& Element::title() {
			return this->_title;
		};
		Element* Element::title(const std::string& title) {
			this->_title = title;
			this->windowRedraw();
			return this;
		};

		Element::Element(elemId_t id, elemId_t parentWindow, elemId_t parent) {
			this->id = id;
			this->parent = parent;
			this->parentWindow = parentWindow;
			this->__current_type = &typeid(Element);
			this->style = new Style(this);
		}

		void Element::__drawBase(int wwidth, int wheight) {
			
		}

		Element* Element::windowReviewZ() {
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
		}

		Element* Element::hide() {
			return this;
		}
		Element* Element::show() {
			return this;
		}

		Element* Element::emit(const elemId_t& eventId, Event::baseEvent* e) {
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
		};

		void Element::removeSelf() {
			delete this;
		}
		Element::~Element() {
			delete this->style;
		}
	}
}