#include <iostream>
#include "GUIGL/Elements/Container.h"
#include "GUIGL/Elements/Element.h"
#include "GUIGL/Elements/ElementContainer.h"
#include <string>

#include <Math.h>

using namespace GUI;
using namespace Elements;
using namespace std;


namespace GUI {
	class GC : public GUI::Elements::Container{
	public:
		Element* operator<<(Element* elem) {
			cout << "gc el add" << endl;
			this->linkElement(elem);
			return elem;
		}
		virtual ~GC() {
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
		}
	};
}

#define GUI_GC_SCOPE GUI::GC __gui_gc_scope__
#define gc_add __gui_gc_scope__ <<
#define gc_new gc_add new


int main() {
	
	/*
	cout << "scope1 start" << endl;
	{
		GUI_GC_SCOPE;
		cout << "	scope1 elements:" << __gui_gc_scope__.elements.size() << endl;

		Element* elem_1 = gc_new Element();
		Element* elem_2 = gc_new Element();
		Element* elem_3 = gc_new Element();
		Element* elem_4 = gc_new Element();
		Element* elem_5 = gc_new Element();
		
		cout << "	scope1 elements:" << __gui_gc_scope__.elements.size() << endl;
	}
	cout << "scope1 end" << endl;

	Container tmpc;

	cout << "scope2 start" << endl;
	{
		GUI_GC_SCOPE;
		cout << "	scope2 elements:" << __gui_gc_scope__.elements.size() << endl;

		Element* elem_1 = gc_new Element();
		Element* elem_2 = gc_new Element();
		Element* elem_3 = gc_new Element();
		Element* elem_4 = gc_new Element();
		Element* elem_5 = gc_new Element();

		tmpc.linkElement(elem_1);
		tmpc.linkElement(elem_2);
		tmpc.linkElement(elem_3);
		tmpc.linkElement(elem_4);
		tmpc.linkElement(elem_5);

		cout << "	scope2 elements:" << __gui_gc_scope__.elements.size() << endl;
	}
	cout << "scope2 end" << endl;
	cout << "======================================" << endl;

	ElementContainer *ec = new ElementContainer;
	ElementContainer* ec2 = new ElementContainer;
	Container *cc = new Container;

	Element *elem1 = new Element();
	Element *elem2 = new Element();
	Element *elem3 = new Element();

	for(int i = 0; i < 10000; i ++)
		ec->addElement(elem1);

	cout << "elem1 csize " << elem1->containers.size()<<endl;
	cout << "ec esize " << ec->elements.size()<<endl;
	cout << "===============================" << endl;

	for (int i = 0; i < 10000; i++)
		ec->addElement(elem2);

	cout << "elem1 csize " << elem1->containers.size() << endl;
	cout << "elem2 csize " << elem2->containers.size() << endl;
	cout << "ec esize " << ec->elements.size() << endl;
	cout << "===============================" << endl;

	for (int i = 0; i < 10000; i++)
		ec->unlinkElement(elem2),
		ec->unlinkElement(elem2),
		ec->unlinkElement(elem2),
		ec->addElement(elem2);

	cout << "elem1 csize " << elem1->containers.size() << endl;
	cout << "elem2 csize " << elem2->containers.size() << endl;
	cout << "ec esize " << ec->elements.size() << endl;
	cout << "===============================" << endl;

	ec->unlinkElement(elem2);

	cout << "elem1 csize " << elem1->containers.size() << endl;
	cout << "elem2 csize " << elem2->containers.size() << endl;
	cout << "ec esize " << ec->elements.size() << endl;
	cout << "===============================" << endl;
	
	ec->addElement(elem3);

	cout << "elem1 csize " << elem1->containers.size() << endl;
	cout << "elem3p csize " << elem3->containers.size() << endl;
	cout << "ec esize " << ec->elements.size() << endl;
	cout << "===============================" << endl;

	elem3->removeSelf();
	elem3 = new Element;

	cout << "elem1 csize " << elem1->containers.size() << endl;
	cout << "ec esize " << ec->elements.size() << endl;
	cout << "===============================" << endl;

	ec->unlinkAll();

	cout << "ec esize " << ec->elements.size() << endl;
	cout << "===============================" << endl;

	ec->addElement(elem1);
	ec->addElement(elem2);
	ec->addElement(elem3);

	cc->linkElement(elem1);
	cc->linkElement(elem2);
	cc->linkElement(elem3);

	cout << "ec esize " << ec->elements.size() << endl;
	cout << "cc esize " << cc->elements.size() << endl;
	cout << "elem1 csize " << elem1->containers.size() << endl;
	cout << "elem2 csize " << elem2->containers.size() << endl;
	cout << "elem3 csize " << elem3->containers.size() << endl;
	cout << "===============================" << endl;

	ec2->addElement(elem3);

	cout << "ec esize " << ec->elements.size() << endl;
	cout << "ec2 esize " << ec2->elements.size() << endl;
	cout << "cc esize " << cc->elements.size() << endl;
	cout << "elem1 csize " << elem1->containers.size() << endl;
	cout << "elem2 csize " << elem2->containers.size() << endl;
	cout << "elem3 csize " << elem3->containers.size() << endl;
	cout << "===============================" << endl;

	ec->removeSelf();

	cout << "cc esize " << cc->elements.size() << endl;
	cout << "===============================" << endl;
	*/
	return 0;
}