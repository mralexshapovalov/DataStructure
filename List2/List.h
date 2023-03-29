#include <iostream>


template<typename T>class List
{
	class Element
	{
		T Data;
		Element* pNext;
		Element* pPrev;

	public:
		Element(T Data, Element* pNext = nullptr, Element* pPrev = nullptr);
		~Element();

		friend class List<T>;

	}*Head, * Tail;

	unsigned int size;
	

	class ConstBaseIterator
	{
	protected:
		Element* Temp;

	public:
		ConstBaseIterator(Element* Temp);
		~ConstBaseIterator();

		bool operator==(const ConstBaseIterator& other)const;
		bool operator!=(const ConstBaseIterator& other)const;
		const T& operator*()const;
	};

public:

	class ConstIterator :public ConstBaseIterator
	{
	public:

		ConstIterator(Element* Temp = nullptr);
		~ConstIterator();
		
		ConstIterator& operator++();
		ConstIterator operator++(int);
		ConstIterator& operator--();
		ConstIterator operator--(int);
	};


	class ConstReverseIterator :public ConstBaseIterator
	{
	public:

		ConstReverseIterator(Element* Temp = nullptr);
		~ConstReverseIterator();
		
		ConstReverseIterator& operator++();
		ConstReverseIterator operator++(int);
		ConstReverseIterator& operator--();
		ConstReverseIterator operator--(int);
		
	};

	class Iterator :public ConstIterator
	{
	public:
		Iterator(Element* Temp);
		~Iterator();

		T& operator*();
	};

	class ReverseIterator :public ConstReverseIterator
	{
	public:
		ReverseIterator(Element* Temp);
		~ReverseIterator();
		
		T& operator*();
	};

	ConstIterator cbegin()const;
	ConstIterator cend()const;

	ConstIterator begin()const;
	ConstIterator end()const;

	Iterator begin();
	Iterator end();
	
	ConstReverseIterator crbegin()const;
	ConstReverseIterator crend()const;
	
	ReverseIterator rbegin();
	ReverseIterator rend();
	
	List();
	List(const std::initializer_list<T>& il);
	~List();
	
	//					Adding elements:
	void push_front(T Data);
	void push_back(T Data);
	void insert(int Index, T Data);
	//				Removing elements:
	void pop_front();
	void pop_back();

	//				Methods:
	void print()const;
	void reverse_print()const;
};

template<typename T>void print(const List<T>& list);
template<typename T>void reverse_print(const List<T>& list);




//#include <iostream>
//#include "Header.h"
//
//
//
//
//
//template<typename T>class List
//{
//	class Element
//	{
//		T Data;
//		Element* pNext;
//		Element* pPrev;
//	public:
//		Element(T Data, Element* pNext = nullptr, Element* pPrev = nullptr)
//			:Data(Data), pNext(pNext), pPrev(pPrev)
//		{
//			cout << "EConstructor:\t" << this << endl;
//		}
//		~Element()
//		{
//			cout << "EDestructor:\t" << this << endl;
//		}
//		friend class List<T>;
//	}*Head, * Tail;
//	unsigned int size;
//
//
//	class ConstBaseIterator
//	{
//	protected:
//		Element* Temp;
//	public:
//		ConstBaseIterator(Element* Temp) :Temp(Temp) {}
//		~ConstBaseIterator() {}
//		bool operator==(const ConstBaseIterator& other)const
//		{
//			return this->Temp == other.Temp;
//		}
//		bool operator!=(const ConstBaseIterator& other)const
//		{
//			return this->Temp != other.Temp;
//		}
//
//		const T& operator*()const
//		{
//			return Temp->Data;
//		}
//	};
//
//
//
//
//public:
//	class ConstIterator :public ConstBaseIterator
//	{
//	public:
//		ConstIterator(Element* Temp = nullptr) :ConstBaseIterator(Temp)
//		{
//#ifdef DEBUG
//			cout << "ItConstructor:\t" << this << endl;
//#endif // DEBUG
//		}
//		~ConstIterator()
//		{
//#ifdef DEBUG
//			cout << "ItDestructor:\t" << this << endl;
//#endif // DEBUG
//		}
//		ConstIterator& operator++()
//		{
//			ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
//			return *this;
//		}
//		ConstIterator operator++(int)
//		{
//			ConstIterator old = *this;
//			ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
//			return old;
//		}
//		ConstIterator& operator--()
//		{
//			ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
//			return *this;
//		}
//		ConstIterator operator--(int)
//		{
//			ConstIterator old = *this;
//			ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
//			return old;
//		}
//	};
//
//
//
//
//	class ConstReverseIterator :public ConstBaseIterator
//	{
//	public:
//		ConstReverseIterator(Element* Temp = nullptr) :ConstBaseIterator(Temp)
//		{
//#ifdef DEBUG
//			cout << "RItConstructor:\t" << this << endl;
//#endif // DEBUG
//		}
//		~ConstReverseIterator()
//		{
//#ifdef DEBUG
//			cout << "RItDestructor:\t" << this << endl;
//#endif // DEBUG
//		}
//		ConstReverseIterator& operator++()
//		{
//			ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
//			return *this;
//		}
//		ConstReverseIterator operator++(int)
//		{
//			ConstReverseIterator old = *this;
//			ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
//			return old;
//		}
//		ConstReverseIterator& operator--()
//		{
//			ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
//			return *this;
//		}
//		ConstReverseIterator operator--(int)
//		{
//			ConstReverseIterator old = *this;
//			ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
//			return old;
//		}
//	};
//	class Iterator :public ConstIterator
//	{
//	public:
//		Iterator(Element* Temp) :ConstIterator(Temp) {}
//		~Iterator() {}
//		T& operator*()
//		{
//			return ConstBaseIterator::Temp->Data;
//		}
//	};
//	class ReverseIterator :public ConstReverseIterator
//	{
//	public:
//		ReverseIterator(Element* Temp) :ConstReverseIterator(Temp) {}
//		~ReverseIterator() {}
//		T& operator*()
//		{
//			return ConstBaseIterator::Temp->Data;
//		}
//	};
//	ConstIterator cbegin()const
//	{
//		return Head;
//	}
//	ConstIterator cend()const
//	{
//		return nullptr;
//	}
//	ConstIterator begin()const
//	{
//		return Head;
//	}
//	ConstIterator end()const
//	{
//		return nullptr;
//	}
//	Iterator begin()
//	{
//		return Head;
//	}
//	Iterator end()
//	{
//		return nullptr;
//	}
//
//	ConstReverseIterator crbegin()const
//	{
//		return Tail;
//	}
//	ConstReverseIterator crend()const
//	{
//		return nullptr;
//	}
//	ReverseIterator rbegin()
//	{
//		return Tail;
//	}
//	ReverseIterator rend()
//	{
//		return nullptr;
//	}
//
//	List()
//	{
//		Head = Tail = nullptr;
//		size = 0;
//		cout << "LConstructor:\t" << this << endl;
//	}
//	List(const std::initializer_list<T>& il) :List()
//	{
//		for (T const* it = il.begin(); it != il.end(); it++)
//		{
//			push_back(*it);
//		}
//	}
//	~List()
//	{
//		//while (Head)pop_front();
//		while (Tail)pop_back();
//		cout << "LDestructor:\t" << this << endl;
//	}
//
//	//					Adding elements:
//	void push_front(T Data)
//	{
//		if (Head == nullptr && Tail == nullptr)
//		{
//			Head = Tail = new Element(Data);
//			size++;
//			return;
//		}
//		Head = Head->pPrev = new Element(Data, Head);
//		size++;
//	}
//	void push_back(T Data)
//	{
//		if (Head == nullptr && Tail == nullptr)return push_front(Data);
//		Tail = Tail->pNext = new Element(Data, nullptr, Tail);
//
//		size++;
//	}
//	void insert(int Index, T Data)
//	{
//		if (Index > size)return;
//
//		Element* Temp;
//		if (Index < size / 2)
//		{
//			Temp = Head;
//			for (int i = 0; i < Index; i++)Temp = Temp->pNext;
//		}
//		else
//		{
//			Temp = Tail;
//			for (int i = 0; i < size - Index - 1; i++)Temp = Temp->pPrev;
//		}
//		Temp->pPrev = Temp->pPrev->pNext = new Element(Data, Temp, Temp->pPrev);
//		size++;
//	}
//
//	//				Removing elements:
//	void pop_front()
//	{
//		if (Head == nullptr && Tail == nullptr)return;
//		if (Head == Tail)
//		{
//			delete Head;
//			Head = Tail = nullptr;
//			return;
//		}
//		//1) Исключаем элемент из списка:
//		Head = Head->pNext;
//		//2) Удаляем элемент из памяти:
//		delete Head->pPrev;
//		//3) Обнуляем адрес удаленного элемента:
//		Head->pPrev = nullptr;
//
//		size--;
//	}
//	void pop_back()
//	{
//		if (Head == Tail)return pop_front();
//		Tail = Tail->pPrev;
//		delete Tail->pNext;
//		Tail->pNext = nullptr;
//		size--;
//	}
//
//	//				Methods:
//	void print()const
//	{
//		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
//		{
//			cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
//		}
//		cout << "Количество элементов списка: " << size << endl;
//	}
//	void reverse_print()const
//	{
//		for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
//			cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
//		cout << "Количество элементов списка: " << size << endl;
//	}
//};