#pragma once
#include <iostream>



#define tab "\t"


////////////////////////////////////////////////////CLASS DECLARETION

template <typename T> class ForwardList;
template <typename T> class Iterator;

template <typename T>
class  Element
{
    T Data; //Значение элемента
    Element<T>* pNext;//Адресс следующего элемента

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
    Iterator(Element<T>* Temp = nullptr);


    ~Iterator();


    Iterator<T>& operator++();


    bool operator ==(const Iterator<T>& other)const;


    bool operator !=(const Iterator<T>& other)const;

    T& operator * ();





};

template <typename T>
class ForwardList
{
    Element<T>* Head;//Голова списка -содержит указатель на нулевой элемент списка
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