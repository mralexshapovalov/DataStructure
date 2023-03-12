// CPP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>

#define tab "\t"
#define line "--------------------------------------------------"

class Element
{

    int Data;        //Значение элемента
    Element* pNext; //адрес следующего элемента

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

class ForwardList //Forward-односвязный,однонаправленный
{
protected:
    Element* Head; //Голова списка -содержит указатель на нулевой элемент списка
    unsigned int size=0;

public:

    ForwardList()
    {
        Head = nullptr;//Если список пуст,то его Голова указывает на 0
        std::cout << "LConstructor:\t" << this << std::endl;
    }

    ~ForwardList()
    {
        std::cout << "LDestructor:\t" << this << std::endl;
    }

    void push_front(int Data)
    {
        //1)Создаем новый элемент:
        Element* New = new Element(Data);
        //2)Новый элемент должен указывать на начало списка:
        New->pNext = Head;
        //3)Голову списка "Переходим" на новый элемент
        Head = New;

    }

    void push_back(int Data)
    {
        if (Head == nullptr)return push_front(Data);
        //1)Создаем новый элемент:
        Element* New = new Element(Data);
        //2)Доходим до конца списка:
        Element* Temp = Head;
        while (Temp->pNext)
        {
            Temp = Temp->pNext;
        }
        //3)Добавляем элемент в конец списка:
        Temp->pNext = New;
    }


    void pop_front()//удаляет элемент c начала списка
    {
      
        Element* New = Head;
            Head = Head->pNext;
            delete New;

           /* size--;*/

    }

   

    void insert(int Data, int index) //вставляет элемент в список по заданному индексу
    {

        if (index == 0)
        {
            push_front(Data);
        }
        else
        {
            Element* previous = this->Head;

            for (int i = 0; i < index - 1; i++)
            {
                previous = previous->pNext;
            }

            Element* newNode = new Element(Data, previous->pNext);
            previous->pNext = newNode;

            size++;
        }
    }

    void erase(int index) 				//удаляет элемент из списка по заданному индекс
    {
        if (index == 0)
        {
            pop_front();
        }
        else
        {
            Element* previous = this->Head;


            for (int i = 0; i < index - 1; i++)
            {
                previous = previous->pNext;
            }

            Element* toDelete = previous->pNext;
            previous->pNext = toDelete->pNext;
            
            delete toDelete;
        
            size--;
        }
    }

    void pop_back()//удаляет элемент c конца списка
    {
        Element* Temp = Head;
        if (Head == nullptr)return;
        if (Head->pNext == nullptr)return pop_front();

        while (Temp->pNext->pNext)
        {
            Temp = Temp->pNext;
        }
      
        delete  Temp->pNext;
        Temp->pNext = nullptr;
        size--;
    }

    void print()const
    {
        Element* Temp = Head; //Temp-это итератор
        //Итератор - это указатель,при помощи которого можно получить доступ
        //к элементам структуры данных

        while (Temp)
        {
            std::cout << Temp << tab << Temp->Data << tab << Temp->pNext << std::endl;
            Temp = Temp->pNext; //Переход на следующий элемент
        }
    }

};




int main()
{
    setlocale(LC_ALL, "Rus");
    int n;
    std::cout << "Введите размер списка"; std::cin >> n;
    ForwardList list;
    std::cout << "Вывод списка" << std::endl;

    for (int i = 0; i < n; i++)
    {
        list.push_front(rand() % 100);
        /*   list.push_back(rand() % 100);*/
    }
    list.print();

    std::cout << line << std::endl;
    std::cout << "Удаление первого элемента из списка" << std::endl;

    list.pop_front();
    for (int i = 0; i < n; i++)
    {
        
    }
    list.print();

  
    std::cout << line << std::endl;
    std::cout << "Удаление элемента по индексу" << std::endl;
    list.erase(3);
    for (int i = 0; i < n; i++)
    {

    }
    list.print();

    std::cout << line << std::endl;
    std::cout << "Добавление элемента по индексу" << std::endl;
 
    list.insert(99,3);
    for (int i = 0; i < n; i++)
    {

    }
    list.print();


    std::cout << line << std::endl;
    std::cout << "Удаление последнего элемента из списка" << std::endl;
    list.pop_back();
    for (int i = 0; i < n; i++)
    {

    }
    list.print();

    /*list.push_back(123);
    list.print();*/

}

