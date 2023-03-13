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

        Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
        {
            std::cout << "Econstructor:\t" << this << std::endl;
        }
        ~Element()
        {
            std::cout << "EDestructor:\t" << this << std::endl;
        }

        friend class ForwardList;
    
};

