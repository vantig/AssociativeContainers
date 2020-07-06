#include<algorithm>
#include<ctime>
#include<fstream>
#include<functional>
#include<iostream>
#include<iterator>
#include<list>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<utility>
#include<vector>
#include<memory>
struct Flowerbed
{
    size_t num;
    std::string shape;
    std::vector<std::string> flowers;
    friend std::istream& operator>>(std::istream& in, Flowerbed& f);

};
std::istream& operator>>(std::istream& in, Flowerbed& f)
{
    std::cout << "shape "<<std::endl;
    in >> f.shape;
    std::cout << "num " << std::endl;
    in >> f.num;

    std::cout << "flowers" << std::endl;
    bool exit = true;
    int count = 0;
    while (exit)
    {
       
           std::string str;
           in >> str;
         f.flowers.push_back(str);
        std::cout << "add flowers ? ";
        std::cin >> exit;
    }
    return in;

}
std::ostream& operator<<(std::ostream& out, const std::pair<std::string,Flowerbed>& f)
{
   
   
    out << "shape " << f.first << std::endl << "num " << f.second.num << std::endl << "flowers ";
    std::copy(f.second.flowers.begin(), f.second.flowers.end(), std::ostream_iterator<std::string>(std::cout, " "));
    out << std::endl;
    return out;
}
namespace std
{
    std::ostream& operator<<(std::ostream& out, const std::pair<int, string>& _pair)
    {
        out << _pair.second << " ";
        return out;
    }

    std::ostream& operator<<(std::ostream& out, const Flowerbed& flowerbed)
    {
        out << flowerbed.num << " " << flowerbed.shape << " ";
        std::copy(flowerbed.flowers.begin(), flowerbed.flowers.end(), std::ostream_iterator<std::string>(std::cout, " "));
        return out;
    }
}

int main()
{
    while (true)
    {
        int choice;
        std::cout << "Task:\n"
            << "(1) river\n"
            << "(2) numbers\n"
            << "(3) std::bind\n"
            << "(4) flowerbed\n"
            << "(0) exit\n"
            << "\nEnter number task: ";
        std::cin >> choice;

        switch (choice)
        {
        case 0:
        {
            return 0;
        }
        case 1:
        {
            std::cout << "\n################## Task 1 ##################\n";
            std::set<std::string> riverBank = { "Sandpiper", "Cancer", "Mussel" };
            std::set<std::string> riverDepth = { "Bull", "Perch", "Mussel" };
            std::set<std::string> riverUnion;
            std::multiset<std::string> riverAll;

            std::cout << "\nSet 1: ";
            std::copy(riverBank.begin(), riverBank.end(), std::ostream_iterator<std::string>(std::cout, " "));
            std::cout << "\n";

            std::cout << "\nSet 2: ";
            std::copy(riverDepth.begin(), riverDepth.end(), std::ostream_iterator<std::string>(std::cout, " "));
            std::cout << "\n";

            //слияние всех обитателей из сетов в один мультисет, при этом повторные объекты добавляются
            std::merge(riverBank.begin(), riverBank.end(), riverDepth.begin(), riverDepth.end(), inserter(riverAll, riverAll.begin()));
            std::cout << "\nMultiset: ";
            std::copy(riverAll.begin(), riverAll.end(), std::ostream_iterator<std::string>(std::cout, " "));
            std::cout << "\n";

            //объединение находит всех обитателей и помещает в riverAll, при этом повторные объекты не добавляются
            std::set_union(riverBank.begin(), riverBank.end(), riverDepth.begin(), riverDepth.end(), inserter(riverUnion, riverUnion.begin()));
            std::cout << "\nUnion: ";
            std::copy(riverUnion.begin(), riverUnion.end(), std::ostream_iterator<std::string>(std::cout, " "));
            std::cout << "\n";

            //пересечение находит общие объекты для riverBank и riverDepth
            std::cout << "\nIntersection: ";
            std::set_intersection(riverBank.begin(), riverBank.end(), riverDepth.begin(), riverDepth.end(), std::ostream_iterator<std::string>(std::cout, " "));
            std::cout << "\n";

            //вычитание находит объекты присущие только одному множеству
            std::set<std::string> bankOnly;
            std::set_difference(riverBank.begin(), riverBank.end(), riverDepth.begin(), riverDepth.end(), inserter(bankOnly, bankOnly.begin()));
            std::cout << "\nDifference (Set 1 - Set 2): ";
            std::copy(bankOnly.begin(), bankOnly.end(), std::ostream_iterator<std::string>(std::cout, " "));
            std::cout << "\n\n############################################\n\n";
            break;
        }
        case 2:
        {
            std::cout << "\n################## Task 2 ##################\n";
            std::multimap<int, std::string> nums =
            { { 1, "адзін" },
                { 1, "один" },
                { 1, "one" },
                { 2, "два" },
                { 2, "two" },
                { 3, "тры" },
                { 3, "три" },
                { 3, "three" },
                { 4, "чатыры" },
                { 4, "четыре" },
                { 4, "four" } };

            std::multimap<int, std::string>::iterator it_low, it_upp; //it_low, it_upp - встроенные в multimap итераторы
            int key;
            std::cout << "\nEnter key (1 - 4): ";
            std::cin >> key;
            it_low = nums.lower_bound(key); //ищет первое вхождение ключа и возвращает итератор
            it_upp = nums.upper_bound(key); //ищет последнее вхождение ключа и возвращает итератор

            if (it_low != nums.end()) //если первое вхождение ключа найдено
            {
                std::copy(it_low, it_upp, std::ostream_iterator<std::pair<int, std::string>>(std::cout, "\n"));
            }
            else
            {
                std::cout << "No such key!\n";
            }

            std::cout << "\n############################################\n\n";
            break;
        }

        case 3:
        {
            std::cout << "\n################## Task 3 ##################\n";
            size_t size = 15;
            std::vector<int> nums(size);

            //заполняем вектор рандомными числами от 0 до 99
            std::for_each(nums.begin(), nums.end(), [](int& i) { i = rand() % 100; });

            //выводим начальный вектор на консоль
            std::cout << "\nNumbers:\n";
            std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout, " "));
            std::cout << "\n";

            std::cout << "\nEnter number x (0 - 99): ";
            int key;
            std::cin >> key;

            //bind позволяет изменять количество аргументов и сами аргументы функтора (функции), а placeholders определяет на какую позицию из параметров функтора (функции)
            std::cout << "\nNumber more x:\n";
            std::copy_if(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout, " "), std::bind(std::greater<int>(), std::placeholders::_1, key));
            std::cout << "\n\n############################################\n\n";
            break;
        }
        case 4:
        {
            std::cout << "\n################## Task 4 ##################\n";
            std::list<Flowerbed> list;
            std::ifstream file("Text.txt");

            if (file) //проверка на открытие файла
            {
                std::string str;

                while (getline(file, str))
                {
                    Flowerbed flowerbed;
                    std::istringstream ss(str);
                    ss >> flowerbed.num >> flowerbed.shape;
                    std::copy(std::istream_iterator<std::string>(ss), std::istream_iterator<std::string>(), std::inserter(flowerbed.flowers, flowerbed.flowers.begin()));
                    list.push_back(flowerbed);
                }
            }
            else
            {
                std::cout << "Error open file!\n";
            }

            while (true)
            {
                int choice;
                bool flag = false;
                std::cout << "\nOperation:\n"
                    << "(1) print complete information\n"
                    << "(2) print all types of flowers\n"
                    << "(3) sort by shape\n"
                    << "(4) map\n"
                    << "(0) exit\n"
                    << "\nEnter number operation: ";
                std::cin >> choice;

                switch (choice)
                {
                case 0:
                {
                    flag = true;
                    break;
                }
                case 1:
                {
                    std::copy(list.begin(), list.end(), std::ostream_iterator<Flowerbed>(std::cout, "\n"));
                    break;
                }
                case 2:
                {
                    std::set<std::string> flowers;

                    for (auto ptr = list.begin(); ptr != list.end(); ptr++)
                    {

                        for (auto ptr1 = ptr->flowers.begin(); ptr1 != ptr->flowers.end(); ptr1++)
                        {
                            flowers.insert(*ptr1);
                        }

                    }

                    std::copy(flowers.begin(), flowers.end(), std::ostream_iterator<std::string>(std::cout, " "));
                    break;
                }
                case 3:
                {
                    list.sort([](const Flowerbed& a, const Flowerbed& b)
                        {
                            return a.shape < b.shape;
                        });
               
                std::for_each(list.begin(), list.end(), [](Flowerbed& flowerbed)
                    {
                        std::cout << flowerbed.shape<<" ";
                    });
                }
                case 4:
                {
                    std::multimap<std::string, Flowerbed>MyMap;
                    std::for_each(list.begin(), list.end(), [&MyMap](Flowerbed& f) {MyMap.emplace(f.shape, f); });
                    for (auto i = MyMap.begin(); i != MyMap.end(); ++i)
                    {
                        std::cout << *i;
                    }
                    
                    std::cout << "\nOperation:\n"
                        << "(1) add\n"
                        << "(2) delete\n"
                        << "(3) replacement\n";
                    int choise1;
                   std:: cin >> choise1;
                   switch (choise1)
                   {
                   case 1:
                   {
                      Flowerbed f;
                      std::cin >> f;
                      MyMap.emplace(f.shape, f);
                           
                   }
                   case 2:
                   { std::cout << "shape? ";
                       std::string str;
                       std::cin >> str;
                       MyMap.erase(str);
                   }
                   case 3:
                   {
                       std::cout << "shape? ";
                       std::string str;
                  
                       std::cin >> str;
                       Flowerbed f1;
                       std::cin >> f1;
                    auto find=   MyMap.find(str);
                     
                     
                                       
                                      
                      
                   }
                   default:
                       break;
                   }

                }
                default:
                {
                    break;
                }
                }

                if (flag)
                {
                    break;
                }
            }

            break;
        }
        default:
        {
            std::cout << "Havent task with this number!\n";
        }
        }
    }
}