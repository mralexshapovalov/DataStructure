#include "Elements.h"


 Element:: Element(int Data, Element* pNext) :Data(Data), pNext(pNext)
 {
      std::cout << "Econstructor:\t" << this << std::endl;
 }
 Element::~Element()
 {
      std::cout << "EDestructor:\t" << this << std::endl;
 }
