// BinaryThree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Three
{
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;

	public:

		

		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr) :Data(Data), pLeft(pLeft), pRight(pRight)
		{
			std::cout << "EConstructor:\t" << this << std::endl;
		}

		~Element()
		{
			{
				std::cout << "EDestructor:\t" << this << std::endl;
			}
		}
		

		friend class Three;

	}*Root;

public:
	Element* getRoot()
	{
		return Root;
	}

	Three() :Root(nullptr)
	{
		std::cout << "TConstructor" << this << std::endl;
	}
	~Three()
	{
		std::cout << "TDestructor" << this << std::endl;
	}

	void insert(int Data,Element *Root)
	{

		if (Root == nullptr) return;

		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else
		{
			if(Root->pRight== nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}



};

int main()
{
	int n;
	std::cin >> n;

	Three three;

	for (int i = 0; i < n; i++)
	{
		three.insert(rand() % 100, three.getRoot());
	}
}

