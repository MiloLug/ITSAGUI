#pragma once
#include "../defs.h"
#include <vector>
#include "Element.h"

namespace GUI {
	namespace Elements {
		class Container
		{
		public:
			static const std::type_info* __base_type;
			const std::type_info* __current_type;

			std::vector<std::pair<elemId_t, elemId_t>*> elements;

			Container();
			virtual Container* addElement(Element* elem);

			virtual bool hasElelemt(elemId_t wid, elemId_t eid);

			//Container* Container::unlinkElement(elemId_t eid);

			virtual Container* removeAll();

			virtual void removeSelf();
			virtual ~Container();
		};
	}
}