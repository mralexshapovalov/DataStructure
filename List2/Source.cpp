﻿// List2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
//#include "List.h"
#include "List.cpp"

using namespace std;

#define tab "\t"





//#define BASE_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef BASE_CHECK
	int n;
	cout << "Введите размер списка: "; cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}
	list.print();
	list.reverse_print();

	int index;
	int value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	list.insert(index, value);
	list.print();
	list.reverse_print();
#endif // BASE_CHECK

	List<int> list = { 3, 5, 8, 13, 21 };

	//list.print();
	for (int i : list)
	{
		cout << i << tab;
	}
	cout << endl;

	for (int& i : list)i *= 10;

	print(list);
	for (List<int>::ReverseIterator rit = list.rbegin(); rit != list.rend(); rit++)*rit /= 10;
	reverse_print(list);

	List<double> d_list = { 2.5, 3.14, 8.3, 4.7 };
	for (double i : d_list)cout << i << tab; cout << endl;
}
