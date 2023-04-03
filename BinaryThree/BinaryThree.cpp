#include <iostream>

#define DEBUG
class Three
{
protected:

	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;

	public:

		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr)
			:Data(Data), pLeft(pLeft), pRight(pRight)
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

	Three(const std::initializer_list<int>& il) :Three()
	{
		for (int i : il)insert(i);
	}
	Three(const Three& other) :Three()
	{
		Copy(other.Root);
	}


	~Three()
	{
		clear(Root);
		std::cout << "TDestructor" << this << std::endl;
	}

	

	void insert(int Data)
	{
		insert(Data, Root);
	}

	int minValue()const
	{
		return minValue(Root);
	}

	int maxValue()const
	{
		return maxValue(Root);
	}

	int Count()const
	{
		return Count(Root);
	}
	


	int Sum()const
	{
		return Sum(Root);
	}
	void clear()
	{
		clear(Root);
		Root = nullptr;
	}

	double Avg()
	{

		return (double)Sum(Root) / Count(Root);
	}

	int Depth()const
	{
		return Depth(Root);
	}

	void Copy(Element* Root)
	{
		if (Root == nullptr)return;
		insert(Root->Data, this->Root);
		Copy(Root->pLeft);
		Copy(Root->pRight);

	}

	void Print()const
	{
		print(Root);
		std::cout << std::endl;

	}

private:

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


	

	

	int Count(Element* Root)const
	{
		if (Root == nullptr)return 0;
		else  return Count(Root->pLeft) + Count(Root->pRight) + 1;
	}

	int Sum(Element* Root)const
	{
		if (Root == nullptr)return 0;
		else return  Sum(Root->pLeft) + Sum(Root->pRight) + Root->Data;
	}

	

	//////////////////////////////////////////////////////////////////////////////////
	void clear(Element* Root)
	{
		if (Root == nullptr)return;
		clear(Root->pLeft);
		clear(Root->pRight);
		delete Root;
	}

	int Depth(Element* Root)const
	{
		/*if (Root == nullptr) return 0;

		int leftDepth = Depth(Root->pLeft);
		int rightDepth = Depth(Root->pRight);

		if (leftDepth <= rightDepth)
		{
			return rightDepth+1;
		}

		else
		{
			return leftDepth+1;
		}*/

		if (Root == nullptr)return 0;


	/*	if (Depth(Root->pLeft) + 1 > Depth(Root->pRight) + 1) return Depth(Root->pLeft)+1;
		else return Depth(Root->pRight) + 1;*/

		int leftDepth = Depth(Root->pLeft)+1;
		int rightDepth = Depth(Root->pRight)+1;

		return leftDepth < rightDepth ? rightDepth : leftDepth;

		/*if (Root == nullptr)return 0;

		return Depth(Root->pLeft) + 1 >
			Depth(Root->pRight) + 1 ?
			Depth(Root->pLeft) :
			Depth(Root->pRight);*/


	}

	void print(Element* Root)const
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		std::cout << Root->Data << "\t";
		print(Root->pRight);

	}
};

class UniqueTree :public Three
{


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
public:

	void insert(int Data)
	{
		insert(Data, Root);
	}
};


//#define BASE_CHECK

#define DEPTH_CHECK

int main()
{
#ifdef BASE_CHECK

	int n;
	std::cin >> n;
	Three three;

	for (int i = 0; i < n; i++)
	{
		three.insert(rand() % 100);
	}

	three.Print();

	UniqueTree three2;
	for (int i = 0; i < n; i++)
	{
		three2.insert(rand() % 100);
	}
	//three2.print( three2.getRoot());

	std::cout << std::endl;
	std::cout << "Min value : " << three.minValue() << std::endl;
	std::cout << "Max value : " << three.maxValue() << std::endl;
	std::cout << "Values :" << three.Count();
	std::cout << std::endl;
	std::cout << "Values2 :" << three2.Count() << std::endl;
	std::cout << "Sum :" << three.Sum() << std::endl;
	std::cout << "Avg :" << three.Avg() << std::endl;
	std::cout << "Depth :" << three.Depth() << std::endl;

	three.Print();

	std::cout << "\n" << "CLEAR" << std::endl;
	three.clear();
	three.Print();
#endif // BASE_CHECK

#ifdef DEPTH_CHECK
	Three three = { 50,25,75,16,32,64,80,48,49 };
	three.Print();

	std::cout << "Depth: " << three.Depth() << std::endl;
#endif // DEPTH_CHECK

	Three three2 = three;
	three2.Print();


}
