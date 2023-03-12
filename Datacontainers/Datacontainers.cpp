// Datacontainers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#define line "--------------------------------------------------------"

template<typename T>
class List
{
    public:
        List();
        ~List();

        void push_back(T data);
        void pop_front();
        void clear();
        void push_front(T data);
        void insert(T data, int index);
        void removeAt(int index);
        void pop_back();
        int get_Size() { return size; }
        T& operator[](const int index);

private:

    template<typename T>

    class Node
    {
    public:

        Node* pNext;
        T data;

        Node(T data=T(), Node* pNext = nullptr)
        {
            this->data = data;
            this -> pNext = pNext;

        }
      
    };
    int size;
    Node<T> *head;
};
template<typename T>
List<T>::List()
{
    size = 0;
    head = nullptr;

}

template<typename T>
List<T>::~List()
{
    clear();
}

template<typename T>
void List<T>::push_back(T data)
{
    if (head==nullptr)
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T>* current = this->head;
        while (current->pNext !=nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);

    }
    size++;

}
template<typename T>
void List<T>::pop_front()
{

    Node<T> *Temp = head;
    head = head->pNext;
    delete Temp;

    size--;

}

template<typename T>
void List<T>::clear()
{
    while (size)
    {
        pop_front();

    }
}

template<typename T>
void List<T>::push_front(T data)
{
    head = new Node<T>(data,head);
    size++;

}

template<typename T>
void List<T>::insert(T data, int index)
{
    if (index == 0)
    {
        push_front(data);
    }
    else
    {
        Node<T>* previous = this->head;

        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }

        Node<T>* newNode = new Node<T>(data, previous->pNext);
        previous->pNext = newNode;

        size++;
    }
}

template<typename T>
void List<T>::removeAt(int index)
{
    if (index == 0)
    {
        pop_front();
    }
    else
    {
        Node<T>* previous = this->head;

        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }

        Node<T>* toDelete = previous->pNext;
        previous->pNext = toDelete->pNext;
        delete toDelete;

        size--;
    }
}

template<typename T>
void List<T>::pop_back()
{
    removeAt(size - 1);
}



template<typename T>
T& List<T>::operator[](const int index)
{
    int counter = 0;
    Node<T>* current = this->head;

    while (current !=nullptr)
    {
        if (counter == index)
        {

            return current->data;

        }
        current = current->pNext;
        counter++;
    }
}

int main()
{


    List<int>lst;
    lst.push_back(5);
    lst.push_back(10);
    lst.push_back(122);
    lst.push_back(123);
    
   /* for (int i = 0; i < 7; i++)
    {
        lst.push_back(rand() % 10);
    }*/



    for (int i = 0; i < lst.get_Size(); i++)
    {
        std::cout << lst[i] << std::endl;
    }
 
    lst.pop_front();

    std::cout << line << std::endl;

    for (int i = 0; i < lst.get_Size(); i++)
    {
        std::cout << lst[i] << std::endl;
    }
    std::cout << line << std::endl;
    lst.insert(99, 1);
    for (int i = 0; i < lst.get_Size(); i++)
    {
        std::cout << lst[i] << std::endl;
    }

    std::cout << line << std::endl;
    lst.removeAt(1);
    for (int i = 0; i < lst.get_Size(); i++)
    {
        std::cout << lst[i] << std::endl;
    }

    std::cout << line << std::endl;
    lst.pop_back();
    for (int i = 0; i < lst.get_Size(); i++)
    {
        std::cout << lst[i] << std::endl;
    }
}
    
    //std::cout << lst[2] << std::endl;



