#pragma once
#include <iostream>
#include <conio.h>
#define tab "\t"

class Element
{
private:

        int Data;        //�������� ��������
        Element* pNext; //����� ���������� ��������

 public:

     Element(int Data, Element* pNext = nullptr) ;  
     ~Element();

     friend class ForwardList;
    
};

