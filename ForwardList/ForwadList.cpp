// CPP.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
//


#include "Elements.h"
#include "ForList.h"

#define line "--------------------------------------------------"


int main()
{
    setlocale(LC_ALL, "Rus");
    int n;
    std::cout << "������� ������ ������:"; std::cin >> n;
    ForwardList list;
    std::cout << "����� ������" << std::endl;

    for (int i = 0; i < n; i++)
    {
        list.push_front(rand() % 100);
        /*   list.push_back(rand() % 100);*/
    }
    list.print();

    std::cout << line << std::endl;
    std::cout << "�������� ������� �������� �� ������" << std::endl;
    list.pop_front();
    list.print();

    std::cout << line << std::endl;
    std::cout << "�������� �������� �� �������" << std::endl;
    list.erase(3);
    list.print();

    std::cout << line << std::endl;
    std::cout << "���������� �������� �� �������" << std::endl;
    list.insert(99,3);
    list.print();

    std::cout << line << std::endl;
    std::cout << "�������� ���������� �������� �� ������" << std::endl;
    list.pop_back();
    list.print();
}

