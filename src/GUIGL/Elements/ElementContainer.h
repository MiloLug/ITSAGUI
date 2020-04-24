#pragma once
#ifndef __ELEMENTS_ELEMENTCONTAINER

#define __ELEMENTS_ELEMENTCONTAINER

#include "../defs.h"
#include <functional>
#include "Container.h"
#include "Element.h"

namespace GUI {
	namespace Elements {
		//predec
		class Element;
		class Container;
		
		class ElementContainer : public Container, public Element
		{
		public:
			static const std::type_info* __base_type;
			const std::type_info* __current_type;

			ElementContainer(elemId_t id, elemId_t parentWindow = 0, elemId_t parent = 0);
			
			virtual ElementContainer* addElement(Element* elem);
			
			virtual void __drawBase(int wwidth, int wheight);
			
			virtual ~ElementContainer();
			virtual void removeSelf();
		};
	}
}

#endif
