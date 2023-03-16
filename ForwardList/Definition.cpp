
#include"ForwardList.h"




template <typename T>int Element<T>::count = 0; //Инициализируем статическую переменную,объявленную в классе "Element"

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

template <typename T>bool Iterator<T>:: operator ==(const Iterator<T>& other)const
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
    Head = nullptr;//Если список пуст,то его Голова указывает на 0
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
    //1) Создаем новый элемент:
    Element* New = new Element(Data);
    //2) Новый элемент должен указывать на начало списка:
    New->pNext = Head;
    //3) Голову списка "переводим" на новый элемент:
    Head = New;
    */

    Head = new Element<T>(Data, Head);

    size++;
}

template <typename T>void ForwardList<T>::push_back(T Data)
{
    if (Head == nullptr)return push_front(Data);
    //1) Создаем новый элемент:
    Element<T>* New = new Element<T>(Data);
    //2) Доходим до конца списка:
    Element<T>* Temp = Head;
    while (Temp->pNext)
        Temp = Temp->pNext;
    //3) Добавляем элемент в конец списка:
    Temp->pNext = new Element<T>(Data);
    size++;
}

template <typename T>void ForwardList<T>::insert(int index, T Data)
{

    if (index == 0)return push_front(Data);
    if (index > size)return;

    //1) Создаем новый элемент:
    Element<T>* New = new Element<T>(Data);

    //2) Доходим до нужного элемента
    Element<T>* Temp = Head;
    for (int i = 0; i < index - 1; i++)if (Temp->pNext)Temp = Temp->pNext;

    //3) Вставляем новый элемент в список:

    Temp->pNext = new Element<T>(Data, Temp->pNext);
    size++;
}

template <typename T> void ForwardList<T>::pop_front()
{
    Element< T >* Erased = Head;	//1) запоминаем адрес удаляемого элемента
    Head = Head->pNext;		//2) исключаем элемент из стписка
    delete Erased;			//3) удаляем элемент из памяти

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
    //Element* Temp = Head;	//Temp - это итератор
    ////Итератор - это указатель, при помощи которого можно получить доступ
    ////к элементам структуры данных
    //while (Temp)
    //{
    //    std::cout << Temp << tab << Temp->Data << tab << Temp->pNext << std::endl;
    //    Temp = Temp->pNext;	//Переход на следующий элемент
    //}
    for (Element< T >* Temp = Head; Temp; Temp = Temp->pNext)
        std::cout << Temp << tab << Temp->Data << tab << Temp->pNext << std::endl;
    std::cout << "Количество элементов списка:" << size << std::endl;
    std::cout << "Общее количество элементов: " << Element< T >::count << std::endl;
}