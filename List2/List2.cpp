// List2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#define tab "\t"

class List
{

	class Element
	{
		int Data;
		Element* pNext; //Указатель на следующий элемент
		Element* pPrev; //Указатель на предыдущий элемент

	public:

		Element(int Data, Element* pNext = nullptr, Element* pPrev = nullptr) :Data(Data), pNext(pNext), pPrev(pPrev)
		{
			std::cout << "EConstructor" << this << std::endl;
		}
		~Element()
		{
			std::cout << "EDestructor" << this << std::endl;
		}

		friend class List;
	}*Head, *Tail;

	unsigned int size;
public :
	List()
	{
		Head = Tail = nullptr;
		size = 0;
		std::cout << "LConstructor" << this << std::endl;
	}

	~List()
	{
		//while (Head)pop_front();
		while (Tail)pop_back();
		std::cout << "LDestructor" << this << std::endl;
	}

	//Adding Elemnents:

	void push_front(int Data)
	{
		if (Head == nullptr && Tail == nullptr)
		{
			Head = Tail = new Element(Data);
			size++;
			return;//Используется в качестве прерывание цикла
		}

		Element* New = new Element(Data);
		New->pNext = Head;
		Head->pPrev = New;
		Head = New;

		size++;

	}

	void push_back(int Data)
	{
		if (Head == nullptr && Tail == nullptr) return push_front(Data);

		Element* New = new Element(Data);
		New->pPrev = Tail;
		Tail->pNext = New;
		Tail = New;

		size++;
	}
	void pop_front()
	{
		if (Head == nullptr && Tail == nullptr) return;

		if (Head == Tail)
		{
			delete Head;
			Head = Tail = nullptr;
			return;
		}

		Head = Head->pNext;
		delete Head->pPrev;
		Head->pPrev = nullptr;

		size--;

	}

	void pop_back()
	{
		
		if (Head == Tail) return pop_front();

		Tail = Tail->pPrev;
		delete Tail->pNext;

		Tail->pNext = nullptr;
		size--;

	}
	
	void print()const

	{
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
		{
			std::cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << std::endl;

			
		}
		std::cout << "Number of values : " << size << std::endl;
	}

	void reverse_print()const

	{
		for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
		{
			std::cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << std::endl;

			
		}
		std::cout << "Number of values : " << size << std::endl;
	}

	void insert(int Index, int Data)
	{
		if (Index == 0)return push_front(Data); //Если Индекс равен нулю,до добавляем элемент в начало списка
		if (Index > size)return;    // Если Индекс элемента находится в не диапазона размера значений,то произсодит прерывания условия

		Element* Temp;
		Element* New = new Element(Data);
		if (Index < size / 2)
		{
			Temp = Head;
			for (int i = 0; i < Index; i++)Temp = Temp->pNext;

		}

		else 
		{
			Temp = Tail;

			for (int i = 0; i< size - Index - 1; i++)Temp = Temp->pPrev;
		}

		
		New->pNext = Temp;
		New->pPrev = Temp->pPrev;
		Temp->pPrev->pNext = New;
		Temp->pPrev = New;

		size++;

	}

	void earse(int Index)
	{

	}
	

};



int main()
{
   

	setlocale(LC_ALL, "rus");

	int n;
	std::cout << "Enter the number of items "; std::cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}
	list.print();
	
	list.insert(2, 15);
	list.insert(3, 16);
	list.print();

}

