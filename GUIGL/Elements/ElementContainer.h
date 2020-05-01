#pragma once
#ifndef __ELEMENTS_ELEMENTCONTAINER

#define __ELEMENTS_ELEMENTCONTAINER

#include "../common.h"
#include <functional>
#include "Container.h"
#include "Element.h"

namespace GUI {
	namespace Elements {
		class ElementContainer : public Container, public Element
		{
		public:
//base type info =========================
			static const std::type_info* __base_type;
			virtual const std::type_info* __current_type();
//data =========================

//constructor =========================
			ElementContainer();

//some methods =========================	
			virtual ElementContainer* addElement(Element* elem);
			virtual ElementContainer* removeElement(Element* elem);

			virtual ElementContainer* linkElement(Element* elem);
			virtual ElementContainer* unlinkElement(Element* elem);

			virtual ElementContainer* unlinkAll();
			virtual ElementContainer* removeAll();

			virtual void __drawBase(int wwidth, int wheight);
			
			virtual void removeSelf();
			virtual ~ElementContainer();
		};
	}
}

#endif
