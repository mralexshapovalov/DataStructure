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



	std::string a;
	std::cin >> a;

	std::map<std::string, std::string> myMap;

	myMap.emplace(a, "вызов");
	myMap.emplace(a, "Cvfsf");

	//auto it = myMap.find(a);


	//std::cout << it->second << std::endl;



	std::cout << myMap[a] << std::endl;


	std::multimap<int, std::string> week =
	{
		std::pair<int, std::string>(0, "Sunday"),
		std::pair<int, std::string>(1, "Monday"),
		std::pair<int, std::string>(2, "Tuesday"),
		{3, "Wednesday"},
		{4, "Thursday"},
		{5, "Friday"},
		{6, "Saturday"},
		{7, "Sunday"},
		{7, "Sunday"},
		{7, "Sunday"},
	};
	for (std::map<int, std::string>::iterator it = week.begin(); it != week.end(); ++it)
	{
		std:: cout << it->first << " - " << it->second << std::endl;
	}
}

