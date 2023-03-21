// CPP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#define tab "\t"
#include <algorithm>    // std::reverse
#include <vector> 
class ForwardList;

class Element
{
	int Data;		//значение элемента
	Element* pNext;	//адрес следующего элемента
	static int count;
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		count++;
#ifdef DEBUG
		cout << "EConstructor:\t" << this << endl;
#endif // DEBUG

	}
	~Element()
	{
		count--;
#ifdef DEBUG
		cout << "EDestructor:\t" << this << endl;
#endif // DEBUG

	}
	friend class ForwardList;
	friend class Iterator;
	friend class ConstIterator;
};

int Element::count = 0;	//Инициализируем статическу переменную, объявленную в классе 'Element'

class ConstIterator
{
	Element* Temp;
public:
	ConstIterator(Element* Temp = nullptr) :Temp(Temp)
	{
#ifdef DEBUG
		cout << "ItConstructor:\t" << this << endl;
#endif // DEBUG
	}
	~ConstIterator()
	{
#ifdef DEBUG
		cout << "ItDestructor:\t" << this << endl;
#endif // DEBUG
	}

	ConstIterator& operator++()
	{
		Temp = Temp->pNext;
		return *this;
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
class Iterator
{
	Element* Temp;
public:
	Iterator(Element* Temp = nullptr) :Temp(Temp)
	{
#ifdef DEBUG
		cout << "ItConstructor:\t" << this << endl;
#endif // DEBUG
	}
	~Iterator()
	{
#ifdef DEBUG
		cout << "ItDestructor:\t" << this << endl;
#endif // DEBUG
	}

	Iterator& operator++()
	{
		Temp = Temp->pNext;
		return *this;
	}

	bool operator==(const Iterator& other)const
	{
		return this->Temp == other.Temp;
	}
	bool operator!=(const Iterator& other)const
	{
		return this->Temp != other.Temp;
	}
	int& operator*()
	{
		return Temp->Data;
	}
};

class ForwardList	//Forward - односвязный, однонаправленный
{
	Element* Head;	//Голова списка - содержит указатель на нулевой элемент списка
	int size;
public:
	ConstIterator cbegin()const
	{
		return Head;
	}
	Iterator begin()
	{
		return Head;
	}

	ConstIterator cend()const
	{
		return nullptr;
	}
	Iterator end()
	{
		return nullptr;
	}

	ForwardList()
	{
		Head = nullptr;	//Если список пуст, то его Голова указывает на 0
		size = 0;
#ifdef DEBUG
		cout << "LConstructor:\t" << this << endl;
#endif // DEBUG

	}
	ForwardList(const std::initializer_list<int>& il) :ForwardList()
	{
		//il - initializer_list
		//initializer_list - это контейнер.
		//Контейнер - это объект, который организует хранение других объектов в памяти.
		//Как и у любого другого контейнера, у initilizer_list есть методы begin() и end()
		//begin() - возвращает итератор на начало контейнера.
		//end()   - возвращает итератор на конец контейнера.
		std::cout << typeid(il.begin()).name() << std::endl;
		for (int const* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}
	}
	ForwardList(const ForwardList& other)
	{
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_front(Temp->Data);
		reverse();
		std::cout << "CopyConstructor:" << this << std::endl;
	}
	~ForwardList()
	{
		while (Head)pop_front();
#ifdef DEBUG
		cout << "LDestructor:\t" << this << endl;
#endif // DEBUG
	}

	//					Adding elements:
	void push_front(int Data)
	{
		/*
		//1) Создаем новый элемент:
		Element* New = new Element(Data);
		//2) Новый элемент должен указывать на начало списка:
		New->pNext = Head;
		//3) Голову списка "переводим" на новый элемент:
		Head = New;
		*/

		Head = new Element(Data, Head);

		size++;
	}
	void push_back(int Data)
	{
		if (Head == nullptr)return push_front(Data);
		//1) Создаем новый элемент:
		//Element* New = new Element(Data);
		//2) Доходим до конца списка:
		Element* Temp = Head;
		while (Temp->pNext)
			Temp = Temp->pNext;
		//3) Добавляем элемент в конец списка:
		Temp->pNext = new Element(Data);
		size++;
	}
	void insert(int Index, int Data)
	{
		if (Index == 0)return push_front(Data);
		if (Index > size)return;

		//1) Создаем новый элемент:
		//Element* New = new Element(Data);

		//2) Доходим до нужного элемента
		Element* Temp = Head;
		for (int i = 0; i < Index - 1; i++)Temp = Temp->pNext;

		//3) Вставляем новый элемент в список:
		//New->pNext = Temp->pNext;
		//Temp->pNext = New;
		Temp->pNext = new Element(Data, Temp->pNext);

		size++;
	}

	//					Erasing Elements
	void pop_front()
	{
		Element* Erased = Head;	//1) запоминаем адрес удаляемого элемента
		Head = Head->pNext;		//2) исключаем элемент из стписка
		delete Erased;			//3) удаляем элемент из памяти

		size--;
	}

	void pop_back()
	{
		Element* Temp = Head;
		while (Temp->pNext->pNext)
		{
			Temp = Temp->pNext;
		}
		delete Temp->pNext;
		Temp->pNext = nullptr;
		size--;
	}

	//					Methods:
	void reverse()
	{
		ForwardList buffer;
		while (Head)
		{
			buffer.push_front(Head->Data);	//Начальный элемент добавляет в начало буфера
			pop_front();	//удаляем начальный элемент из исходного списка
		}
		Head = buffer.Head;
		buffer.Head = nullptr;
	}
	void print()const
	{
		/*Element* Temp = Head;	//Temp - это итератор
		//Итератор - это указатель, при помощи которого можно получить доступ
		//к элементам структуры данных
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;	//Переход на следующий элемент
		}*/
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
			std::cout << Temp << tab << Temp->Data << tab << Temp->pNext << std::endl;

		std::cout << "Количество элементов списка:" << size << std::endl;
		std::cout << "Общее количество элементов: " << Element::count << std::endl;
	}
};

ForwardList operator+(const ForwardList& left, const ForwardList& right)
{
	ForwardList cat;
	for (ConstIterator it = left.cbegin(); it != left.cend(); ++it)	cat.push_back((*it));
	for (ConstIterator it = right.cbegin(); it != right.cend(); ++it)	cat.push_back(*it);
	return cat;
}



//#define BASE_CHECK
//#define BASE_FOREACH

int main()
{
    setlocale(LC_ALL, "Rus");

#ifdef BASE_CHECK

    int n;
    std::cout << "Введите размер списка: "; std::cin >> n;
    ForwardList list;
    for (int i = 0; i < n; i++)
    {
        list.push_front(rand() % 100);
        //list.push_back(rand() % 100);
    }
    list.print();
    //list.push_back(123);

    int value;
    int index;
    std::cout << "Введите индекс добавляемого элемента: "; std::cin >> index;
    std::cout << "Введите значение добавляемого элемента: "; std::cin >> value;
    list.insert(index, value);
    list.print();

    ForwardList list2;
    list2.push_back(3);
    list2.push_back(5);
    list2.push_back(8);

    list2.print();
#endif // BASE_CHECK

#ifdef BASE_FOREACH
    int arr[] = { 3,5,8,12,21 };
    for (int i : arr)
    {
        std::cout << i << tab;
    }
    std::cout << std::endl;

#endif // BASE_FOREACH

  
    ForwardList list = { 3, 5, 8, 13, 21 };

    for (int i : list)
    {
        std::cout << i << tab;
    }

    std::cout << std::endl;
  
    ForwardList list2 = { 34, 55, 89 };
    for (int i : list2)std::cout << i << tab; std::cout << std::endl;

    std::cout << "ВЫПОЛНЯЕТСЯ СЛОЖЕНИЕ _____________________________________________________________";
    ForwardList list3 = list + list2;
    list3.print();
    for (int i : list3)std::cout << i << tab; std::cout << std::endl;

    std::cout << "ВЫПОЛНЯЕТСЯ REVERSE _____________________________________________________________";
    ForwardList list4 = { 3, 5, 8, 13, 21 };
    list4.reverse();
    list4.print();
   /* for (int i : list4)std::cout << i << tab; std::cout << std::endl;*/
    

}

