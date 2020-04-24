#include "Container.h"
#include "ElementsStore.h"

namespace GUI {
	namespace Elements {
		const std::type_info* Container::__base_type = &typeid(Container);

		Container::Container() {
			this->__current_type = &typeid(Container);
		}

		Container* Container::addElement(Element* elem) {
			for (std::pair<elemId_t, elemId_t> *id : this->elements) {
				if (id->first == elem->parentWindow && id->second == elem->id)
					return this;
			}
			ElementsStore::addElement(elem);
			this->elements.push_back(new std::pair<elemId_t, elemId_t>{
				elem->parentWindow, elem->id
			});
			return this;
		}

		bool Container::hasElelemt(elemId_t wid, elemId_t eid) {
			for (std::pair<elemId_t, elemId_t>* id : this->elements) {
				if (id->first == wid && id->second == eid) {
					return true;
				}
				else {
					Element *tmp = ElementsStore::getElement(wid, eid);
					if (tmp->__current_type == Container::__base_type
						|| tmp->__current_type == ElementContainer::__base_type) {
						
						if(((Container*)tmp)->hasElelemt(wid, eid))
							return true;
					}
				}
			}
			return false;
		}

		Container* Container::removeAll() {
			for(std::pair<elemId_t, elemId_t>* id : this->elements) {
				ElementsStore::removeElement(id->first, id->second);
			}
			this->elements.clear();
			return this;
		}

		void Container::removeSelf() {
			this->removeAll();
			delete this;
		}
		Container::~Container() {
			
		}
	}
}