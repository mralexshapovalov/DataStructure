#include <iostream>
#include"Elements.h"

class ForwardList
{
     //Forward-�����������,����������������
    
    protected:
        Element* Head; //������ ������ -�������� ��������� �� ������� ������� ������
        unsigned int size = 0;

    public:

        ForwardList();
        ~ForwardList();
        
        void push_front(int Data);
        
        void push_back(int Data);
        
        void pop_front();//������� ������� c ������ ������
        
        void insert(int Data, int index); //��������� ������� � ������ �� ��������� �������
        
        void erase(int index);			//������� ������� �� ������ �� ��������� ������
        
        void pop_back();//������� ������� c ����� ������
        
        void print()const;
};

