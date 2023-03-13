// CPP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include "Elements.h"
#include "ForList.h"

#define line "--------------------------------------------------"


int main()
{
    setlocale(LC_ALL, "Rus");
    int n;
    std::cout << "Введите размер списка:"; std::cin >> n;
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
    list.print();

    std::cout << line << std::endl;
    std::cout << "Удаление элемента по индексу" << std::endl;
    list.erase(3);
    list.print();

    std::cout << line << std::endl;
    std::cout << "Добавление элемента по индексу" << std::endl;
    list.insert(99,3);
    list.print();

    std::cout << line << std::endl;
    std::cout << "Удаление последнего элемента из списка" << std::endl;
    list.pop_back();
    list.print();
}

