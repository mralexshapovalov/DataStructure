#pragma once
#include <iostream>
#include <conio.h>
#define tab "\t"

class Element
{
private:

        int Data;        //Значение элемента
        Element* pNext; //адрес следующего элемента

 public:

     Element(int Data, Element* pNext = nullptr) ;  
     ~Element();

     friend class ForwardList;
    
};

