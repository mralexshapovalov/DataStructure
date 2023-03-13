
#include <iostream>


class ForwardList
{
     //Forward-�����������,����������������
    
    protected:
        Element* Head; //������ ������ -�������� ��������� �� ������� ������� ������
        unsigned int size = 0;

    public:

        ForwardList()
        {
            Head = nullptr;//���� ������ ����,�� ��� ������ ��������� �� 0
            std::cout << "LConstructor:\t" << this << std::endl;
        }

        ~ForwardList()
        {
            std::cout << "LDestructor:\t" << this << std::endl;
        }

        void push_front(int Data)
        {
            //1)������� ����� �������:
            Element* New = new Element(Data);
            //2)����� ������� ������ ��������� �� ������ ������:
            New->pNext = Head;
            //3)������ ������ "���������" �� ����� �������
            Head = New;
        }

        void push_back(int Data)
        {
            if (Head == nullptr)return push_front(Data);
            //1)������� ����� �������:
            Element* New = new Element(Data);
            //2)������� �� ����� ������:
            Element* Temp = Head;
            while (Temp->pNext)
            {
                Temp = Temp->pNext;
            }
            //3)��������� ������� � ����� ������:
            Temp->pNext = New;
        }

        void pop_front()//������� ������� c ������ ������
        {
            Element* New = Head;
            Head = Head->pNext;
            delete New;
        }

        void insert(int Data, int index) //��������� ������� � ������ �� ��������� �������
        {

            if (index == 0)
            {
                push_front(Data);
            }
            else
            {
                Element* previous = this->Head;

                for (int i = 0; i < index - 1; i++)
                {
                    previous = previous->pNext;
                }

                Element* newNode = new Element(Data, previous->pNext);
                previous->pNext = newNode;

                size++;
            }
        }

        void erase(int index) 				//������� ������� �� ������ �� ��������� ������
        {
            if (index == 0)
            {
                pop_front();
            }
            else
            {
                Element* previous = this->Head;


                for (int i = 0; i < index - 1; i++)
                {
                    previous = previous->pNext;
                }

                Element* toDelete = previous->pNext;
                previous->pNext = toDelete->pNext;

                delete toDelete;

                size--;
            }
        }

        void pop_back()//������� ������� c ����� ������
        {
            Element* Temp = Head;
            if (Head == nullptr)return;
            if (Head->pNext == nullptr)return pop_front();

            while (Temp->pNext->pNext)
            {
                Temp = Temp->pNext;
            }

            delete  Temp->pNext;
            Temp->pNext = nullptr;
            size--;
        }

        void print()const
        {
            Element* Temp = Head; //Temp-��� ��������
            //�������� - ��� ���������,��� ������ �������� ����� �������� ������
            //� ��������� ��������� ������

            while (Temp)
            {
                std::cout << Temp << tab << Temp->Data << tab << Temp->pNext << std::endl;
                Temp = Temp->pNext; //������� �� ��������� �������
            }
        }

    
};

