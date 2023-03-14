// CPP.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
//

#include <iostream>


#define tab "\t"

class Element
{
    int Data; //�������� ��������
    Element* pNext;//������ ���������� ��������

    static int count;

public:

    Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
    {
        count++;
        std::cout << "Econstructor:\t" << this << std::endl;

    }
    ~Element()
    {
        count--;
        std::cout << "EDestuctor:\t" << this << std::endl;

    }
    friend class ForwardList;
};

int Element::count = 0; //�������������� ����������� ����������,����������� � ������ "Element"

class ForwardList
{
    Element* Head;//������ ������ -�������� ��������� �� ������� ������� ������
    int size;

public:

    ForwardList()
    {
        Head = nullptr;//���� ������ ����,�� ��� ������ ��������� �� 0
        size = 0;
        std::cout << "LConstuctor:\t" << this << std::endl;
    }
    ~ForwardList()
    {
        std::cout << "LDestuctor:\t" << this <<std::endl;
    }
    void push_front(int Data)
    {
        /*
        //1) ������� ����� �������:
        Element* New = new Element(Data);
        //2) ����� ������� ������ ��������� �� ������ ������:
        New->pNext = Head;
        //3) ������ ������ "���������" �� ����� �������:
        Head = New;
        */

        Head = new Element(Data, Head);

        size++;
    }

    void push_back(int Data)
    {
        if (Head == nullptr)return push_front(Data);
        //1) ������� ����� �������:
        Element* New = new Element(Data);
        //2) ������� �� ����� ������:
        Element* Temp = Head;
        while (Temp->pNext)
            Temp = Temp->pNext;
        //3) ��������� ������� � ����� ������:
        Temp->pNext = New;
        size++;
    }

    void insert(int index, int Data)
    {

        if (index == 0)return push_front(Data);
        if (index > size)return;

        //1) ������� ����� �������:
        Element* New = new Element(Data);

        //2) ������� �� ������� ��������
        Element* Temp = Head;
        for (int i = 0; i < index - 1; i++)Temp = Temp->pNext;

        //3) ��������� ����� ������� � ������:
        New->pNext = Temp->pNext;
        Temp->pNext = New;
        size++;
    }

    void pop_front()
    {
        Element* Erased = Head;	//1) ���������� ����� ���������� ��������
        Head = Head->pNext;		//2) ��������� ������� �� �������
        delete Erased;			//3) ������� ������� �� ������

        size--;
    }

    void pop_back()
    {
        Element* Temp = Head;
        while (Temp->pNext->pNext)
        {
            Temp = Temp->pNext;
        }
        delete Temp->pNext;
        Temp->pNext = nullptr;
        size--;
    }

    //					Methods:
    void print()const
    {
        Element* Temp = Head;	//Temp - ��� ��������
        //�������� - ��� ���������, ��� ������ �������� ����� �������� ������
        //� ��������� ��������� ������
        while (Temp)
        {
            std::cout << Temp << tab << Temp->Data << tab << Temp->pNext << std::endl;
            Temp = Temp->pNext;	//������� �� ��������� �������
        }
        std::cout << "���������� ��������� ������:" << size << std::endl;
        std::cout << "����� ���������� ���������: " << Element::count << std::endl;
    }
};


int main()
{
    setlocale(LC_ALL, "Rus");
    int n;
    std::cout << "������� ������ ������: "; std::cin >> n;
    ForwardList list;
    for (int i = 0; i < n; i++)
    {
        list.push_front(rand() % 100);
        //list.push_back(rand() % 100);
    }
    list.print();
    //list.push_back(123);

    int value;
    int index;
    std::cout << "������� ������ ������������ ��������: "; std::cin >> index;
    std::cout << "������� �������� ������������ ��������: "; std::cin >> value;
    list.insert(index, value);
    list.print();

    ForwardList list2;
    list2.push_back(3);
    list2.push_back(5);
    list2.push_back(8);
    list2.print();


}

