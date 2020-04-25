# ITSAGUI
## TODO

Learn OpenGL, add shadow, color, borders, text....

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
    elemId_t className

    ElementsStore: add window->zIndex->left->top->width->height->elements map "positionMap",
                   add window->[hovered,pressed]->elements map "stateMap"
                   add window->className->id->element map "attrMap" (it dnt replace window->id->element !)
                   add getElementsByClassName()
                   rename getElement() -> getElementById()
                   
    Rebuild Draw for working with positionMap
    Rebuild mouse events for working with positionMap and stateMap, changing Element::hover/press
    
    Rebuild ALL for working with attrMap

    ???CSS parsing hmmm....
    ?????JSON or HTML parsing...
