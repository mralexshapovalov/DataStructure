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
};

int Element::count = 0; //Инициализируем статическую переменную,объявленную в классе "Element"

class ForwardList
{
    Element* Head;//Голова списка -содержит указатель на нулевой элемент списка
    int size;

public:

    ForwardList()
    {
        Head = nullptr;//Если список пуст,то его Голова указывает на 0
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
        Temp->pNext = New;
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
        for (int i = 0; i < index - 1; i++)Temp = Temp->pNext;

        //3) Вставляем новый элемент в список:
        New->pNext = Temp->pNext;
        Temp->pNext = New;
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
        Element* Temp = Head;	//Temp - это итератор
        //Итератор - это указатель, при помощи которого можно получить доступ
        //к элементам структуры данных
        while (Temp)
        {
            std::cout << Temp << tab << Temp->Data << tab << Temp->pNext << std::endl;
            Temp = Temp->pNext;	//Переход на следующий элемент
        }
        std::cout << "Количество элементов списка:" << size << std::endl;
        std::cout << "Общее количество элементов: " << Element::count << std::endl;
    }
};


int main()
{
    setlocale(LC_ALL, "Rus");
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


}

