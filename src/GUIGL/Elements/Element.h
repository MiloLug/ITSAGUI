#pragma once
#ifndef __ELEMENTS_ELEMENT

#define __ELEMENTS_ELEMENT

#include "../defs.h"
#include <functional>
#include <string>
#include "../Event.h"
#include "Style.h"

namespace GUI {
	namespace Elements {
		class Element
		{
		public:
			static const std::type_info* __base_type;
			const std::type_info* __current_type;

			Style* style;
			
			bool shown = true;
			std::string _title = "";
			
			std::string& title();
			Element* title(const std::string& title);

			elemId_t id;
			elemId_t parentWindow;
			elemId_t parent;

			Element(elemId_t id, elemId_t parentWindow = 0, elemId_t parent = 0);

			virtual void __drawBase(int wwidth, int wheight);

			Element* windowReviewZ();
			Element* windowRedraw();

			virtual Element* hide();
			virtual Element* show();

			virtual Element* emit(const elemId_t& eventId, Event::baseEvent* e);
			virtual Element* emit(const elemId_t& eventId, void* e = nullptr);
	
			virtual Element* on(const elemId_t& eventId, const Event::defaultELFn& fn, void* additionData, Event::defaultELFn*& listenerPtr);
			virtual Element* on(const elemId_t& eventId, const Event::defaultELFn& fn, void* additionData);
			virtual Element* on(const elemId_t& eventId, const Event::defaultELFn& fn, Event::defaultELFn*& listenerPtr);
			virtual Element* on(const elemId_t& eventId, const Event::defaultELFn& fn);
		
			virtual Element* off(const elemId_t& eventId, const Event::defaultELFn& fn);
			virtual Element* off(const elemId_t& eventId, Event::defaultELFn* fn);

			virtual Element* emit(const std::string& eventId, Event::baseEvent* e);
			virtual Element* emit(const std::string& eventId, void* e = nullptr);
	
			virtual Element* on(const std::string& eventId, const Event::defaultELFn& fn, void* additionData, Event::defaultELFn*& listenerPtr);
			virtual Element* on(const std::string& eventId, const Event::defaultELFn& fn, void* additionData);
			virtual Element* on(const std::string& eventId, const Event::defaultELFn& fn, Event::defaultELFn*& listenerPtr);
			virtual Element* on(const std::string& eventId, const Event::defaultELFn& fn);

			virtual Element* off(const std::string& eventId, const Event::defaultELFn& fn);
			virtual Element* off(const std::string& eventId, Event::defaultELFn* fn);

			virtual void removeSelf();
			virtual ~Element();
		};
	}
}

#endif