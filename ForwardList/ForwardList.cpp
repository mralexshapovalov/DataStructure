// CPP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include"Definition.cpp"



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

    int arr[] = { 3,5,8,12,21 };

   

   /* for (int i = 0; i < sizeof(arr) / sizeof (int); i++)
    {
        std::cout << arr[i] << "\t";
    }*/
#ifdef BASE_FOREACH
    int arr[] = { 3,5,8,12,21 };
    for (int i : arr)
    {
        std::cout << i << tab;
    }
    std::cout << std::endl;

#endif // BASE_FOREACH

  
    ForwardList< std::string > s_list = { "HELLO","Frend"};
    s_list.print();
    for (std::string i : s_list)std::cout << i << tab; std::cout << std::endl;
  
    std::cout << std::endl;
}

