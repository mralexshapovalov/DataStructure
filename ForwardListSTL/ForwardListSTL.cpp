// ForwardListSTL.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

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
	
    unsigned int a;

	setlocale(LC_ALL, "RUS");



std::forward_list<int> forwardList = {};
std::forward_list<int>::iterator it = forwardList.begin();





int size = 10;

while (true)
	{
	
	std::cout << "Choose one of the actions" << std::endl;
    std::cout << "1)Добавить элемент в начало списка\n"
		         "7)Отсортировать список\n"
		         ""
	             "8)"
		         "9)Удалить первыйй элемет со списка\n"
		         "10)Очистить весь список\n"
		         "11)Вывести список на экран"
		                                        << std::endl;

	
		std::cin >> a;

		switch (a)
		{
		case 0:


			for (int i = 0; i < size; i++)
			{
				forwardList.push_front(rand() % 100);
			}

			break;

		case 1:

			int n;
			std::cin >> n;
					
			forwardList.push_front(n);

			std::cout << "Значенипе добавлено" << "\n";

			break;

		case 2:


			break;

		case 3:
			break;

		case 4:

			break;

		case 5:
			
			break;


		case 6:

			break;

		case 7:
			if (forwardList.empty() == true)
			{
				std::cout << "ERROR! The list is empty";

			}
			else
			{

				forwardList.sort(); //greather строги	 общий порядок
				for (int i : forwardList)std::cout << i << tab; std::cout << std::endl;

			}

			break;

		case 8:

			break;

		case 9:

			if (forwardList.empty() == true)
			{
				std::cout << "ERROR! The list is empty";

			}
			else
			{

				forwardList.pop_front();

			}
			

			break;

		case 10:

			if (forwardList.empty() == true)
			{
				std::cout << "ERROR! The list is empty\n";

			}
			else
			{

				forwardList.clear();

			}

			break;


		case 11:
			if (forwardList.empty() == true)
			{
				std::cout << "ERROR! The list is empty\n";

			}
			else 
			{
				for (int i : forwardList)std::cout << i << tab; std::cout << std::endl;
			}

			
			break;


		

		default:
			std::cout << "Error\n";
			break;
		}
	}
	
	






}







