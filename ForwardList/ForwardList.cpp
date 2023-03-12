// CPP.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
//

#include <iostream>
#include <conio.h>

#define tab "\t"
#define line "--------------------------------------------------"

class Element
{

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

class ForwardList //Forward-�����������,����������������
{
    Element* Head; //������ ������ -�������� ��������� �� ������� ������� ������

public:

    ForwardList()
    {
        Head = nullptr;//���� ������ ����,�� ��� ������ ��������� �� 0
        std::cout << "LConstructor:\t" << this << std::endl;
    }

    ~ForwardList()
    {
        std::cout << "LDestructor:\t" << this << std::endl;
    }

    void push_front(int Data)
    {
        //1)������� ����� �������:
        Element* New = new Element(Data);
        //2)����� ������� ������ ��������� �� ������ ������:
        New->pNext = Head;
        //3)������ ������ "���������" �� ����� �������
        Head = New;

    }

    void push_back(int Data)
    {
        if (Head == nullptr)return push_front(Data);
        //1)������� ����� �������:
        Element* New = new Element(Data);
        //2)������� �� ����� ������:
        Element* Temp = Head;
        while (Temp->pNext)
        {
            Temp = Temp->pNext;
        }
        //3)��������� ������� � ����� ������:
        Temp->pNext = New;
    }


    void pop_front()//������� ������� c ������ ������
    {
      
        Element* New = Head;
            Head = Head->pNext;
            delete New;

           /* size--;*/

    }

    void pop_back()//������� ������� c ����� ������
    {
       
    
        //2)������� �� ����� ������:
        Element* Temp = Head;
        while (Temp->pNext)
        {
            Temp = Temp->pNext;
        }
        //3)��������� ������� � ����� ������:
        delete Temp;
    }

    void insert(int Data, int Index) //��������� ������� � ������ �� ��������� �������
    {

    }

    void erase(int Index) 				//������� ������� �� ������ �� ��������� ������
    {

    }

    void print()const
    {
        Element* Temp = Head; //Temp-��� ��������
        //�������� - ��� ���������,��� ������ �������� ����� �������� ������
        //� ��������� ��������� ������

        while (Temp)
        {
            std::cout << Temp << tab << Temp->Data << tab << Temp->pNext << std::endl;
            Temp = Temp->pNext; //������� �� ��������� �������
        }
    }

};




int main()
{
    setlocale(LC_ALL, "Rus");
    int n;
    std::cout << "������� ������ ������"; std::cin >> n;
    ForwardList list;

    for (int i = 0; i < n; i++)
    {
        list.push_front(rand() % 100);
        /*   list.push_back(rand() % 100);*/
    }
    list.print();

    std::cout << line << std::endl;
    list.pop_front();
    list.pop_back();

    for (int i = 0; i < n; i++)
    {
        
    }
    list.print();


    /*list.push_back(123);
    list.print();*/

}

