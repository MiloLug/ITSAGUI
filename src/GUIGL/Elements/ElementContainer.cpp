#include "ElementContainer.h"

#include <iostream>
namespace GUI {
	namespace Elements {
		const std::type_info* ElementContainer::__base_type = &typeid(ElementContainer);

		ElementContainer::ElementContainer(elemId_t id, elemId_t parentWindow, elemId_t parent) : Element(id, parentWindow, parent), Container() {
			this->__current_type = &typeid(ElementContainer);
			this->Element::__current_type = &typeid(ElementContainer);
			this->Container::__current_type = &typeid(ElementContainer);
		}

		ElementContainer* ElementContainer::addElement(Element* elem) {
			elem->parentWindow = this->parentWindow;
			elem->parent = this->id;
			this->Container::addElement(elem);
			this->windowReviewZ();
			return this;
		};

		void ElementContainer::__drawBase(int wwidth, int wheight) {
			
		}

		void ElementContainer::removeSelf() {
			this->removeAll();
			delete this;
		}
		ElementContainer::~ElementContainer() {}
	}
}