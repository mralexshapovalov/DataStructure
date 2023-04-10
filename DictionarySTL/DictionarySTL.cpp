// DictionarySTL.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include<iostream>
#include<array>
#include<vector>
#include<deque>
#include<list>
#include<iterator>
#include <forward_list>
#include <map>
#include <string>

#define tab "\t"

int main()
{
	setlocale(LC_ALL, "");

	std::string enterTheWord;
	std::multimap<std::string, std::string> dictionary =
	{
		{"Moon","Луна"},
		{"Moon","Спутник"},
		{"Moon","Лунный месяц"},
		{"Jabber","Болтовня"},
		{"Jabber","Трескотня"},
		{"Jabber","Бормотание"},
		{"Space", "Пробел"},
		{"Space", "Пространство"},
		{"Space", "Космос"},
		{"Set", "Задать"},
		{"Set", "Установить"},
		{"Set", "Набор"},
		{"Call", "Звонок"},
		{"Call", "Вызвать"},
		{"Call", "Назвать"}

	};

	while (true)
	{
		std::cout << "Список слов в словаре:" << std::endl;

		for (std::multimap<std::string, std::string>::iterator it = dictionary.begin(), end = dictionary.end(); it != end; it = dictionary.upper_bound(it->first))
		{
			std::cout << it->first << std::endl;
		}
		std::cout << std::endl;

		std::cout << "Введите слово: "; std::cin >> enterTheWord;
		std::cout << std::endl;

		for (std::multimap<std::string, std::string>::iterator it = dictionary.begin(); it != dictionary.end(); ++it)
		{
			if (it->first == enterTheWord)
			{
				std::cout << it->first << " - " << it->second << std::endl;
			}
		}
		std::cout << std::endl;
	}


}

