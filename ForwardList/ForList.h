#include <iostream>
#include"Elements.h"

class ForwardList
{
     //Forward-односв€зный,однонаправленный
    
    protected:
        Element* Head; //√олова списка -содержит указатель на нулевой элемент списка
        unsigned int size = 0;

    public:

        ForwardList();
        ~ForwardList();
        
        void push_front(int Data);
        
        void push_back(int Data);
        
        void pop_front();//удал€ет элемент c начала списка
        
        void insert(int Data, int index); //вставл€ет элемент в список по заданному индексу
        
        void erase(int index);			//удал€ет элемент из списка по заданному индекс
        
        void pop_back();//удал€ет элемент c конца списка
        
        void print()const;
};

