// List2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#define tab "\t"

class List
{
    class Element
    {
        int Data;
        Element* pNext;
        Element* pPrev;

    public:

        Element(int Data, Element* pNext = nullptr, Element* pPrev = nullptr) :Data(Data), pNext(pNext), pPrev(pPrev)
        {
            std::cout << "Econstructor:\t" << this << std::endl;
        }
        ~Element()
        {
            std::cout << "EDestructor:\t" << this << std::endl;
        }

        friend class  List;
        


    }*Head ,*Tail;

    unsigned int size;
public:
    List()
    {
        Head = Tail = nullptr;
        size = 0;
        std::cout << "Lconstructor:\t" << this << std::endl;
    }
    ~List()
    {
		//while (Head)pop_front();
		while (Tail)pop_back();
        std::cout << "LDestructor:\t" << this << std::endl;
    }
    
    //Adding Elements

	void push_front(int Data)
	{
		if (Head == nullptr && Tail == nullptr)
		{
			
			Head = Tail = new Element(Data);
			size++;
			return;
		}

		Element *New = new Element(Data);
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
	//Remove elment

	void pop_front()
	{

		if (Head == nullptr && Tail == nullptr)
		if (Head == Tail)
		{
				delete Head;
				Head = Tail = nullptr;
				return;
		}
		
		Head = Head->pNext;
		delete Head->pPrev;
		Head->pPrev;

		size--;

	
	}

	void pop_back()
	{
		if (Head == Tail)return pop_front();

		Tail = Tail->pPrev;
		delete Tail->pNext;
		Tail->pNext = nullptr;
		
		size--;
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
	

	

	void print()const
	{
		

		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
		{
			std::cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << std::endl;

		}
		std::cout << "Количество элементов списка:" << size << std::endl;

	}

	void reverse_print()
	{
		std::cout << "REVERSE" << std::endl;

		for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
			std::cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << std::endl;



		std::cout << "Количество элементов списка:" << size << std::endl;
	}

};

int main()
{
   

	setlocale(LC_ALL, "rus");

	List list;
	
	int n; /*std::cin >> n;*/

	for (int i = 0; i <5; i++)
	{

		list.push_front(rand() % 100);
	}

	list.push_back(5);
	list.push_back(6);
	list.print();

}

