// CPP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>


#define tab "\t"

class Element
{
    int Data; //Значение элемента
    Element* pNext;//Адресс следующего элемента

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


int Element::count = 0; //Инициализируем статическую переменную,объявленную в классе "Element"

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
    Element* Head;//Голова списка -содержит указатель на нулевой элемент списка
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
        Head = nullptr;//Если список пуст,то его Голова указывает на 0
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
        //1) Создаем новый элемент:
        Element* New = new Element(Data);
        //2) Новый элемент должен указывать на начало списка:
        New->pNext = Head;
        //3) Голову списка "переводим" на новый элемент:
        Head = New;
        */

        Head = new Element(Data, Head);

        size++;
    }

    void push_back(int Data)
    {
        if (Head == nullptr)return push_front(Data);
        //1) Создаем новый элемент:
        Element* New = new Element(Data);
        //2) Доходим до конца списка:
        Element* Temp = Head;
        while (Temp->pNext)
            Temp = Temp->pNext;
        //3) Добавляем элемент в конец списка:
        Temp->pNext = new Element(Data);
        size++;
    }

    void insert(int index, int Data)
    {

        if (index == 0)return push_front(Data);
        if (index > size)return;

        //1) Создаем новый элемент:
        Element* New = new Element(Data);

        //2) Доходим до нужного элемента
        Element* Temp = Head;
        for (int i = 0; i < index - 1; i++)if (Temp->pNext)Temp = Temp->pNext;

        //3) Вставляем новый элемент в список:
     
        Temp->pNext = new Element(Data,Temp->pNext);
        size++;
    }

    void pop_front()
    {
        Element* Erased = Head;	//1) запоминаем адрес удаляемого элемента
        Head = Head->pNext;		//2) исключаем элемент из стписка
        delete Erased;			//3) удаляем элемент из памяти

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
        //Element* Temp = Head;	//Temp - это итератор
        ////Итератор - это указатель, при помощи которого можно получить доступ
        ////к элементам структуры данных
        //while (Temp)
        //{
        //    std::cout << Temp << tab << Temp->Data << tab << Temp->pNext << std::endl;
        //    Temp = Temp->pNext;	//Переход на следующий элемент
        //}
        for(Element *Temp=Head;Temp;Temp=Temp->pNext)
            std::cout << Temp << tab << Temp->Data << tab << Temp->pNext << std::endl;
        std::cout << "Количество элементов списка:" << size << std::endl;
        std::cout << "Общее количество элементов: " << Element::count << std::endl;
    }
};

//#define BASE_CHECK
//#define BASE_FOREACH

int main()
{
    setlocale(LC_ALL, "Rus");

#ifdef BASE_CHECK

    int n;
    std::cout << "Введите размер списка: "; std::cin >> n;
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
    std::cout << "Введите индекс добавляемого элемента: "; std::cin >> index;
    std::cout << "Введите значение добавляемого элемента: "; std::cin >> value;
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

