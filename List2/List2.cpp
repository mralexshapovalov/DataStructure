// List2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#define tab "\t"

class Iterator;
class ReverseIterator;

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
	class Iterator
	{
		Element* Temp;

	public:
		Iterator(Element* Temp = nullptr) :Temp(Temp)
		{
			std::cout << "ITConstructor" << this << std::endl;
		}
		~Iterator()
		{
			std::cout << "ITDestructor" << this << std::endl;

		}

		Iterator& operator++()
		{
			Temp = Temp->pNext;
			return *this;

		}
		Iterator operator++(int)
		{
			Iterator old = *this;
			Temp = Temp->pNext;
			return old;

		}
		Iterator& operator--()
		{
			Temp = Temp->pPrev;
			return *this;

		}
		Iterator operator--(int)
		{
			Iterator old = *this;
			Temp = Temp->pPrev;
			return old;

		}

		bool operator==(const Iterator& other)const
		{
			return this->Temp == other.Temp;
		}
		bool operator!=(const Iterator& other)const
		{
			return this->Temp != other.Temp;
		}
		const int& operator*()const
		{
			return Temp->Data;
		}

		int& operator*()
		{
			return Temp->Data;
		}


	};

	class ConstIterator
	{
		Element* Temp;
	public:
		ConstIterator(Element* Temp = nullptr) :Temp(Temp)
		{

			std::cout << "ItConstructor:\t" << this << std::endl;

		}
		~ConstIterator()
		{

			std::cout << "ItDestructor:\t" << this << std::endl;

		}

		ConstIterator& operator++()
		{
			Temp = Temp->pNext;
			return *this;

		}
		ConstIterator operator++(int)
		{
			ConstIterator old = *this;
			Temp = Temp->pNext;
			return old;

		}
		ConstIterator& operator--()
		{
			Temp = Temp->pPrev;
			return *this;

		}
		ConstIterator operator--(int)
		{
			ConstIterator old = *this;
			Temp = Temp->pPrev;
			return old;

		}

		bool operator==(const ConstIterator& other)const
		{
			return this->Temp == other.Temp;
		}
		bool operator!=(const ConstIterator& other)const
		{
			return this->Temp != other.Temp;
		}
		const int& operator*()const
		{
			return Temp->Data;
		}
	};



	class ReverseIterator
	{
		Element* Temp;
	public:

		ReverseIterator(Element* Temp = nullptr) :Temp(Temp)
		{
			std::cout << "RItConstructor" << this << std::endl;
		}
		~ReverseIterator()
		{
			std::cout << "RItDestructor" << this << std::endl;

		}
		ReverseIterator& operator++()
		{
			Temp = Temp->pPrev;
			return *this;

		}
		ReverseIterator operator++(int)
		{
			ReverseIterator old = *this;
			Temp = Temp->pPrev;
			return old;

		}
		ReverseIterator& operator--()
		{
			Temp = Temp->pNext;
			return *this;

		}
		ReverseIterator operator--(int)
		{
			ReverseIterator old = *this;
			Temp = Temp->pNext;
			return old;

		}

		bool operator==(const ReverseIterator& other)const
		{
			return this->Temp == other.Temp;
		}
		bool operator!=(const ReverseIterator& other)const
		{
			return this->Temp != other.Temp;
		}
		const int& operator*()const
		{
			return Temp->Data;
		}

		int& operator*()
		{
			return Temp->Data;
		}

	};

	class ConstReverseIterator
	{
		Element* Temp;
	public:

		ConstReverseIterator(Element* Temp = nullptr) :Temp(Temp)
		{
			std::cout << "CConstReverseIterator" << this << std::endl;
		}
		~ConstReverseIterator()
		{
			std::cout << "DestConstReverseIterator" << this << std::endl;

		}
		ConstReverseIterator& operator++()
		{
			Temp = Temp->pPrev;
			return *this;

		}
		ConstReverseIterator operator++(int)
		{
			ConstReverseIterator old = *this;
			Temp = Temp->pPrev;
			return old;

		}
		ConstReverseIterator& operator--()
		{
			Temp = Temp->pNext;
			return *this;

		}
		ConstReverseIterator operator--(int)
		{
			ConstReverseIterator old = *this;
			Temp = Temp->pNext;
			return old;

		}

		bool operator==(const ConstReverseIterator& other)const
		{
			return this->Temp == other.Temp;
		}
		bool operator!=(const ConstReverseIterator& other)const
		{
			return this->Temp != other.Temp;
		}
		const int& operator*()const
		{
			return Temp->Data;
		}

		int& operator*()
		{
			return Temp->Data;
		}

	};



	Iterator begin()
	{
		return Head;
	}

	
	Iterator end()
	{
		return nullptr;
	}

	ReverseIterator rbegin()
	{
		return Tail;
	}


	ReverseIterator rend()
	{
		return nullptr;
	}

	ConstIterator cbegin()const
	{
		return Head;
	}
	ConstIterator cend()const
	{
		return nullptr;
	}

	ConstReverseIterator crbegin()const
	{
		return Tail;
	}


	ConstReverseIterator crend()const
	{
		return nullptr;
	}


	List()
	{
		Head = Tail = nullptr;
		size = 0;
		std::cout << "LConstructor" << this << std::endl;
	}
	List(const std::initializer_list<int>& il) :List()
	{
		for (int const* it = il.begin(); it != il.end(); ++it)
		{
			push_back(*it);
		}
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

		/*Element* New = new Element(Data);
		New->pNext = Head;
		Head->pPrev = New;
		Head = New;*/
		Head = Head->pPrev = new Element(Data, Head);
		size++;

	}

	void push_back(int Data)
	{
		if (Head == nullptr && Tail == nullptr) return push_front(Data);

	/*	Element* New = new Element(Data);
		New->pPrev = Tail;
		Tail->pNext = New;
		Tail = New;*/

		Tail = Tail->pNext = new Element(Data, nullptr, Tail);

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


	    
		/*
		New->pNext = Temp->pPrev
		New->pPrev = Temp->pPrev;
		Temp->pPrev->pNext = New;
		Temp->pPrev = New;*/

	    Temp->pPrev=Temp->pPrev->pNext = new Element(Data, Temp, Temp->pPrev);

		size++;

	}

	void erase(int index)
	{
	
		if (index==0) 
			return pop_front();
		if (index == size - 1) 
			return pop_back();
		if (index >= size)
			return; 
		

		Element* Temp;

		if (index < size / 2)
		{
			Temp = Head;
			for (int i = 0; i < index; i++) Temp = Temp->pNext;
		}
		else
		{
			Temp = Tail;
			for (int i = 0; i < size - index - 1; i++) Temp = Temp->pPrev;
		}
		
		Element* Temp;

		Temp->pPrev->pNext = Temp->pNext; 
		Temp->pNext->pPrev = Temp->pPrev; 

		//В указатель pNext(pPrev) элемент Temp->pPrev(Temp->pNext->pPrev) записывает адрес элемента Temp->pNext(Temp->pPrev)

		delete Temp;
		
		size--;
	}
	
	
};

void print(const List& list)
{
	
	/*List::ConstIterator it;
	for (int i : it= list.cbegin())
	{
		std::cout << i << tab << std::endl;
	}
	std::cout << std::endl;*/

	for (List::ConstIterator it = list.cbegin(); it != list.cend(); ++it)
	{
		std::cout << *it << tab;
	}
	std::cout << std::endl;

	
}

void  reverse_print(const List&  list)
{

	for (List::ConstReverseIterator rit = list.crbegin(); rit != list.crend(); ++rit)
	{
		std::cout << *rit << tab;
	}
	std::cout << std::endl;
}


//#define BASE_CHECK

int main()
{


	setlocale(LC_ALL, "rus");
#ifdef BASE_CHECK
	int n = 5;
	std::cout << "Enter the number of items ";
	List list;
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}
	list.print();

	list.insert(2, 15);
	list.insert(3, 16);
	list.print();

#endif // 0



	List list = { 3,5,7,13,21 };
	//list.print();
	print(list);
	reverse_print(list);
	list.erase(2);
	print(list);
}
