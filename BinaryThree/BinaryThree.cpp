#include <iostream>

class Three
{
protected:

	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;

	public:

		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr) :Data(Data), pLeft(pLeft), pRight(pRight)
		{
			/*std::cout << "EConstructor:\t" << this << std::endl;*/
		}

		~Element()
		{
			{
				/*std::cout << "EDestructor:\t" << this << std::endl;*/
			}
		}

		friend class Three;
		friend class UniqueTree;

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
		clear(Root);
		std::cout << "TDestructor" << this << std::endl;
	}

	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr) return;

		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}

	int minValue(Element* Root)const
	{

		/*if (Root == nullptr) return 0;
		if (Root->pLeft == nullptr)return Root->Data;
		return minValue(Root->pLeft);*/

		if (Root == nullptr) return 0;
		/* if (Root->pLeft == nullptr)return Root->Data;
		 return minValue(Root->pLeft);*/

		return Root->pLeft == nullptr ? Root->Data : minValue(Root->pLeft);
	}

	int maxValue(Element* Root)const
	{
		if (Root == nullptr) return 0;

		return Root->pRight ? maxValue(Root->pRight) : Root->Data;
	}


	void print(Element* Root)const
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		std::cout << Root->Data << "\t";
		print(Root->pRight);
	}

	void clear()
	{
		clear(Root);
		Root = nullptr;
	}

	int Depth()const
	{
		return Depth(Root);
	}

	int Count(Element* Root)
	{
		if (Root == nullptr)return 0;
		else  return Count(Root->pLeft) + Count(Root->pRight) + 1;
	}

	int Sum(Element* Root)const
	{
		if (Root == nullptr)return 0;
		else return  Sum(Root->pLeft) + Sum(Root->pRight) + Root->Data;
	}

	double Avg()
	{

		return (double)Sum(Root) / Count(Root);
	}

	void clear(Element* Root)
	{
		if (Root == nullptr)return;
		clear(Root->pLeft);
		clear(Root->pRight);
		delete Root;
	}

	int Depth(Element* Root)const
	{
		if (Root == nullptr) return 0;

		int leftDepth = Depth(Root->pLeft);
		int rightDepth = Depth(Root->pRight);

		if (leftDepth <= rightDepth)
		{
			return rightDepth+1;
		}

		else
		{
			return leftDepth+1;
		}
	}
};

class UniqueTree :public Three
{

public:

	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr) return;

		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}

		else if (Data > Root->Data)
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
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
		three.insert(rand() % 47, three.getRoot());
	}
	three.print(three.getRoot());

	UniqueTree three2;
	for (int i = 0; i < n; i++)
	{
		three2.insert(rand() % 100, three2.getRoot());
	}
	//three2.print( three2.getRoot());

	std::cout << std::endl;
	std::cout << "Min value : " << three.minValue(three.getRoot()) << std::endl;
	std::cout << "Max value : " << three.maxValue(three.getRoot()) << std::endl;
	std::cout << "Values :" << three.Count(three.getRoot()) << std::endl;
	std::cout << std::endl;
	std::cout << "Values2 :" << three2.Count(three2.getRoot()) << std::endl;
	std::cout << "Sum :" << three.Sum(three.getRoot()) << std::endl;
	std::cout << "Avg :" << three.Avg() << std::endl;
	std::cout << "Depth :" << three.Depth() << std::endl;

	three.print(three.getRoot());

	std::cout << "\n" << "CLEAR" << std::endl;
	three.clear();
	three.print(three.getRoot());
}