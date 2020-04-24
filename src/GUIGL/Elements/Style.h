#pragma once
#ifndef __ELEMENTS_STYLE

#define __ELEMENTS_STYLE

#include <array>
#include <map>
namespace GUI {
	namespace Elements {
		class Element;
	}
}

#define STYLE_POSITION_ABSOLUTE 0
#define STYLE_POSITION_RELATIVE 1

namespace GUI {
	namespace Elements {
		class Style
		{
		public:
			static std::map<std::string, short int> _position_keys;
			static std::map<short int, std::string> _position_values;

			bool __customZ = false;

			short int _position = 1;
			int _zIndex = 0;
			float _width = 0;
			float _height = 0;
			float _left = 0;
			float _top = 0;
			float _padding = 0;
			float _background[4];
			float _shadow[8];

			Element* element;

			Style(Element* elem);

			short int position(); //get
			Style* position(short int position); //set
			Style* position(std::string position); //set

			int zIndex(); //get
			Style* zIndex(int zIndex); //set

			float width(); //get
			Style* width(float width); //set

			float height(); //get
			Style* height(float height); //set

			float left(); //get
			Style* left(float left); //set

			float top(); //get
			Style* top(float top); //set

			float padding(); //get
			Style* padding(float padding); //set

			std::array<float, 4> background(); //get
			Style* background(float r, float g, float b, float a = 1); //set

			std::array<float, 8> shadow(); //get
			Style* shadow(float xOffset, float yOffset, float blurRadius, float spread, float r, float g, float b, float a = 1); //set
		};
	}
}

#endif