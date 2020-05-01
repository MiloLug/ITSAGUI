#include "ElementContainer.h"

#include <iostream>
namespace GUI {
	namespace Elements {
//base type info =========================
		const std::type_info* ElementContainer::__base_type = &typeid(ElementContainer);
		const std::type_info* ElementContainer::__current_type() {
			return &typeid(ElementContainer);
		}
//data =========================

//constructor =========================
		ElementContainer::ElementContainer() : Element(), Container() {
			
		}

//some methods =========================
		ElementContainer* ElementContainer::addElement(Element* elem) {
			if (elem->parent != nullptr) {
				if (elem->parent == this)
					return this;
				((ElementContainer*)elem->parent)->unlinkElement(elem);
			}
			elem->parent = this;
			elem->parentWindow = this->parentWindow;
			elem->__linkContainer(this);
			this->elements.insert(elem);
			return this;
		};
		ElementContainer* ElementContainer::removeElement(Element* elem) {
			if (elem->parent == this) {
				elem->removeSelf();
			}
			return this;
		};

		ElementContainer* ElementContainer::linkElement(Element* elem) {
			return this->addElement(elem);
		};

		ElementContainer* ElementContainer::unlinkElement(Element* elem) {
			if (elem->parent == this) {
				elem->parent = nullptr;
				elem->parentWindow = nullptr;
				elem->__unlinkContainer(this);
				this->elements.erase(elem);
			}
			return this;
		};

		ElementContainer* ElementContainer::unlinkAll() {
			std::unordered_set<Element*>::iterator iter = this->elements.begin(),
				end = this->elements.end();
			for (; (iter != end); iter++) {
				(*iter)->parent = nullptr;
				(*iter)->parentWindow = nullptr;
				(*iter)->__unlinkContainer(this);
			}
			this->elements.clear();
			return this;
		};

		ElementContainer* ElementContainer::removeAll() {
			std::unordered_set<Element*>::iterator iter = this->elements.begin();
			Element* tmp;
			while (iter != this->elements.end()) {
				tmp = *iter;
				iter = this->elements.erase(iter);
				tmp->parent = nullptr;
				tmp->parentWindow = nullptr;
				if (tmp->__containersCount() == 1)
					tmp->removeSelf();
				else
					tmp->__unlinkContainer(this);
			}
			return this;
		};

		void ElementContainer::__drawBase(int wwidth, int wheight) {}

		void ElementContainer::removeSelf() {
			this->removeAll();
			delete this;
		}
		ElementContainer::~ElementContainer() {}
	}
}