# ITSAGUI
## TODO

style branches:

class StyleContainer {

    type styleName = ...
    bool styleName_default
    getter/setter styleName
  
    ...
  
 }

class Style

    StyleContainer Style::plain
    StyleContainer Style::hover
    StyleContainer Style::press

    getter/setter styleName
}

    bool Element::hover
    bool Element::press

ElementsStore: add window->zIndex->left->top->width->height->elements map
Rebuild Draw for working with that map
Rebuild mouse events for working with that map and changing Element::hover/press
