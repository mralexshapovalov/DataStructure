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
    friend class Iterator;
};


int Element::count = 0; //�������������� ����������� ����������,����������� � ������ "Element"

class Iterator
{
    Element* Temp;

public:
    Iterator(Element* Temp = nullptr) :Temp(Temp)
    {
        std::cout << "IConstuctor:\t" << this << std::endl;

    }
    ~Iterator()
    {
        std::cout << "IDestuctor:\t" << this << std::endl;
    }

    Iterator& operator++()
    {
        Temp = Temp->pNext;
        return *this;
    }

    bool operator ==(const Iterator& other)const
    {

        return this->Temp == other.Temp;

    }

    bool operator !=(const Iterator& other)const
    {

        return this->Temp == other.Temp;

    }
    int& operator * ()
    {
        return Temp->Data;
    }




};

class ForwardList
{
    Element* Head;//������ ������ -�������� ��������� �� ������� ������� ������
    int size;

public:
    Iterator begin()
    {
        return Head;
    }

    Iterator end()
    {
        return nullptr;
    }

    ForwardList()
    {
        Head = nullptr;//���� ������ ����,�� ��� ������ ��������� �� 0
        size = 0;
        std::cout << "LConstuctor:\t" << this << std::endl;

    }
    ForwardList(const std::initializer_list<int> &il) :ForwardList()
    {
        //il-initializer_list
        std::cout << typeid(il.begin()).name() << std::endl;
        for (int const* it = il.begin(); it != il.end(); it++)
        {
            push_back(*it);
        }
    }
    ~ForwardList()
    {
        while (Head)pop_front();
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
        Temp->pNext = new Element(Data);
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
        for (int i = 0; i < index - 1; i++)if (Temp->pNext)Temp = Temp->pNext;

        //3) ��������� ����� ������� � ������:
     
        Temp->pNext = new Element(Data,Temp->pNext);
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
        //Element* Temp = Head;	//Temp - ��� ��������
        ////�������� - ��� ���������, ��� ������ �������� ����� �������� ������
        ////� ��������� ��������� ������
        //while (Temp)
        //{
        //    std::cout << Temp << tab << Temp->Data << tab << Temp->pNext << std::endl;
        //    Temp = Temp->pNext;	//������� �� ��������� �������
        //}
        for(Element *Temp=Head;Temp;Temp=Temp->pNext)
            std::cout << Temp << tab << Temp->Data << tab << Temp->pNext << std::endl;
        std::cout << "���������� ��������� ������:" << size << std::endl;
        std::cout << "����� ���������� ���������: " << Element::count << std::endl;
    }
};

//#define BASE_CHECK
//#define BASE_FOREACH

int main()
{
    setlocale(LC_ALL, "Rus");

#ifdef BASE_CHECK

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
#endif // BASE_CHECK

    int arr[] = { 3,5,8,12,21 };

   

   /* for (int i = 0; i < sizeof(arr) / sizeof (int); i++)
    {
        std::cout << arr[i] << "\t";
    }*/
#ifdef BASE_FOREACH
    int arr[] = { 3,5,8,12,21 };
    for (int i : arr)
    {
        std::cout << i << tab;
    }
    std::cout << std::endl;

#endif // BASE_FOREACH

  
    ForwardList list = { 3,4,5,12,13 };
    list.print();
    for (int i : list)
    {
        std::cout << i << tab;
    }
    std::cout << std::endl;
}

