// CPP.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
//

#include <iostream>



#define tab "\t"
template <typename T> class ForwardList;
template <typename T> class Iterator;

template <typename T>
class  Element
{
    T Data; //�������� ��������
    Element<T>* pNext;//������ ���������� ��������

    static int count;

public:

    Element(T Data, Element<T>* pNext = nullptr);
    ~Element();
   
    friend class ForwardList<T>;
    friend class Iterator<T>;
};






 template <typename T>
class Iterator
{
    Element<T>* Temp;
public:
    Iterator(Element<T>* Temp = nullptr) ;
    

    ~Iterator();
    

    Iterator<T>& operator++();
    

    bool operator ==(const Iterator<T>& other)const;
   

    bool operator !=(const Iterator<T>& other)const;
    
    T& operator * ();
    




};

template <typename T>
class ForwardList
{
    Element<T>* Head;//������ ������ -�������� ��������� �� ������� ������� ������
    int size;

public:
    Iterator<T> begin();
        
   

    Iterator<T> end();
    

    ForwardList();
    ForwardList(const std::initializer_list< T >& il);

    ~ForwardList();

    void push_front(T Data);

    void push_back(T Data);

    void insert(int index, T Data);

    void pop_front();

    void pop_back();





    //					Methods:
    void print()const;
};



template <typename T>int Element<T>::count = 0; //�������������� ����������� ����������,����������� � ������ "Element"

template <typename T> Element<T>::Element(T Data, Element<T>* pNext) :Data(Data), pNext(pNext)
{
    count++;
    std::cout << "Econstructor:\t" << this << std::endl;

}
template <typename T>Element<T>::~Element()
{
    count--;
    std::cout << "EDestuctor:\t" << this << std::endl;

}



template <typename T>Iterator<T>::Iterator(Element<T>* Temp) :Temp(Temp)
{
    std::cout << "IConstuctor:\t" << this << std::endl;

}


template <typename T>Iterator<T>::~Iterator()
{
    std::cout << "IDestuctor:\t" << this << std::endl;
}

template <typename T>Iterator<T>& Iterator<T>:: operator++()
{
    Temp = Temp->pNext;
    return *this;
}

template <typename T>bool Iterator<T>:: operator ==(const Iterator<T>&other)const
{

    return this->Temp == other.Temp;

}

template <typename T>bool Iterator<T>::operator !=(const Iterator<T>& other)const
{

    return this->Temp != other.Temp;

}
template <typename T>T& Iterator<T>::operator * ()
{
    return Temp->Data;
}





template <typename T>Iterator<T> ForwardList<T>::begin()
{
    return Head;
}

template <typename T>Iterator<T> ForwardList<T>::end()
{
    return nullptr;
}

template <typename T>ForwardList<T>::ForwardList()
{
    Head = nullptr;//���� ������ ����,�� ��� ������ ��������� �� 0
    size = 0;
    std::cout << "LConstuctor:\t" << this << std::endl;

}
template <typename T>ForwardList<T>::ForwardList(const std::initializer_list< T >& il) :ForwardList()
{
    //il-initializer_list
    std::cout << typeid(il.begin()).name() << std::endl;
    for (T const* it = il.begin(); it != il.end(); it++)
    {
        push_back(*it);
    }
}

template <typename T>ForwardList<T>::~ForwardList()
{
    while (Head)pop_front();
    std::cout << "LDestuctor:\t" << this << std::endl;
}

template <typename T>void ForwardList<T>::push_front(T Data)
{
    /*
    //1) ������� ����� �������:
    Element* New = new Element(Data);
    //2) ����� ������� ������ ��������� �� ������ ������:
    New->pNext = Head;
    //3) ������ ������ "���������" �� ����� �������:
    Head = New;
    */

    Head = new Element<T>(Data, Head);

    size++;
}

template <typename T>void ForwardList<T>::push_back(T Data)
{
    if (Head == nullptr)return push_front(Data);
    //1) ������� ����� �������:
    Element<T>* New = new Element<T>(Data);
    //2) ������� �� ����� ������:
    Element<T>* Temp = Head;
    while (Temp->pNext)
        Temp = Temp->pNext;
    //3) ��������� ������� � ����� ������:
    Temp->pNext = new Element<T>(Data);
    size++;
}

template <typename T>void ForwardList<T>::insert(int index, T Data)
{

    if (index == 0)return push_front(Data);
    if (index > size)return;

    //1) ������� ����� �������:
    Element<T>* New = new Element<T>(Data);

    //2) ������� �� ������� ��������
    Element<T>* Temp = Head;
    for (int i = 0; i < index - 1; i++)if (Temp->pNext)Temp = Temp->pNext;

    //3) ��������� ����� ������� � ������:

    Temp->pNext = new Element<T>(Data, Temp->pNext);
    size++;
}

template <typename T> void ForwardList<T>:: pop_front()
{
    Element< T >* Erased = Head;	//1) ���������� ����� ���������� ��������
    Head = Head->pNext;		//2) ��������� ������� �� �������
    delete Erased;			//3) ������� ������� �� ������

    size--;
}

template <typename T>void ForwardList<T>::pop_back()
{
    Element< T >* Temp = Head;
    while (Temp->pNext->pNext)
    {
        Temp = Temp->pNext;
    }
    delete Temp->pNext;
    Temp->pNext = nullptr;
    size--;
}


//					Methods:
template <typename T>void ForwardList<T>::print()const
{
    //Element* Temp = Head;	//Temp - ��� ��������
    ////�������� - ��� ���������, ��� ������ �������� ����� �������� ������
    ////� ��������� ��������� ������
    //while (Temp)
    //{
    //    std::cout << Temp << tab << Temp->Data << tab << Temp->pNext << std::endl;
    //    Temp = Temp->pNext;	//������� �� ��������� �������
    //}
    for (Element< T >* Temp = Head; Temp; Temp = Temp->pNext)
        std::cout << Temp << tab << Temp->Data << tab << Temp->pNext << std::endl;
    std::cout << "���������� ��������� ������:" << size << std::endl;
    std::cout << "����� ���������� ���������: " << Element< T >::count << std::endl;
}



















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

  
    ForwardList< std::string > s_list = { "HELLO","Frend"};
    s_list.print();
    for (std::string i : s_list)std::cout << i << tab; std::cout << std::endl;
  
    std::cout << std::endl;
}

