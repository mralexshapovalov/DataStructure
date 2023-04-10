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
	setlocale(LC_ALL, "RUS");
	unsigned int value;
	int size;

	std::forward_list<int> forwardList = {};
	std::forward_list<int>::iterator it = forwardList.begin();

	while (true)
	{
		std::cout << "0)Добавить рандомные значения\n"
			"1)Добавить элемент в начало списка\n"
			"2)Отсортировать список\n"
			"3)Удалить первыйй элемет со списка\n"
			"4)Очистить весь список\n"
			"5)Удалить дубликаты в списке\n"
			"6)Вывести список на экран" << std::endl;
		std::cout << "Введите необходимую цифру:"; std::cin >> value;

		switch (value)
		{
		case 0:

			std::cout << "Введите размер списка :"; std::cin >> size;
			for (int i = 0; i < size; i++)
			{
				forwardList.push_front(rand() % 10);
			}
			for (int i : forwardList)std::cout << i << tab; std::cout << std::endl;
			std::cout << "Добавлены значения в кол-ве : " << size << std::endl;

			break;

		case 1:

			std::cout << "Введите значение :"; std::cin >> value;
			forwardList.push_front(value);
			std::cout << "Значенипе добавлено\n";

			break;

		default:

			if (forwardList.empty() == true)
			{
				std::cout << "Ошибка!Невозомжно выполнить действие так как список пуст." << std::endl;
			}
			else
			{
				switch (value)
				{
				case 2:

					forwardList.sort(); //greather строги	 общий порядок
					for (std::forward_list<int>::iterator it = forwardList.begin(); it != forwardList.end(); ++it)
					{
						std::cout << *it << tab;
					}
					std::cout << std::endl;
					break;

				case 3:

					forwardList.pop_front();
					std::cout << "Первый элемент был удален" << std::endl;
					std::cout << std::endl;
					break;

				case 4:

					forwardList.clear();
					std::cout << "Список пуст" << std::endl;
					break;

				case 5:

					for (std::forward_list<int>::iterator it = forwardList.begin(); it != forwardList.end(); ++it)
					{
						std::cout << *it << tab;
					}
					std::cout << std::endl;

					forwardList.unique();
					std::cout << "Уникальный список" << std::endl;

					for (std::forward_list<int>::iterator it = forwardList.begin(); it != forwardList.end(); ++it)
					{
						std::cout << *it << tab;
					}
					std::cout << std::endl;
					break;

				case 6:

					for (std::forward_list<int>::iterator it = forwardList.begin(); it != forwardList.end(); ++it)
					{
						std::cout << *it << tab;
					}
					std::cout << std::endl;
					break;

				default:
					std::cout << "Ошибка!Неправильно выбрана цифра.Повторите снова\n";
					break;
				}

			}
		}
	}
}







