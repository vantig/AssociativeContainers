#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<set>
using std::set;
#include<algorithm>
#include<iterator>
#include"Windows.h"
#include<string>
using std::string;
#include<map>
using std::multimap;
#include<utility>
#include<vector>
using std::vector;
#include<ctime>
#include<functional>

namespace std
{
	std::ostream& operator<<(std::ostream& out, const std::pair<int, string>& _pair)
	{
		out << _pair.second << " ";
		return out;
	}
}

int main()
{
	srand(time(0));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choice;
	cout << "Enter num of task\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		set<string> riverBank = { "пескарь", "рак" };
		set<string> riverDepth = { "бычок", "окунь", "мидия" };

		set<string> all;
		//объединение находит всех обитателей и помещает в all
		std::set_union(riverBank.begin(), riverBank.end(), riverDepth.begin(),
			riverDepth.end(), inserter(all, all.begin()));
		cout << "Union:\n";
		std::copy(all.begin(), all.end(), std::ostream_iterator<string>(cout, " "));
		cout << endl;

		//пересечение находит общие для riverBank и riverDepth объекты
		cout << "Intersection:\n";
		std::set_intersection(riverBank.begin(), riverBank.end(), riverDepth.begin(),
			riverDepth.end(), std::ostream_iterator<string>(cout, " "));
		cout << endl;

		//вычитание находит объекты присущие только одному множеству, но не другому
		set<string> bankOnly;
		std::set_difference(riverBank.begin(), riverBank.end(), riverDepth.begin(),
			riverDepth.end(), inserter(bankOnly, bankOnly.begin()));
		cout << "Difference:\n";
		std::copy(bankOnly.begin(), bankOnly.end(), std::ostream_iterator<string>(cout, " "));
		cout << endl;
	}
	break;
	case 2:
	{
		multimap<int, string> nums = {
		{ 1, "адзін" },
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

		//it - встроенный в multimap итератор
		multimap<int, string>::iterator it, it1;
		int key;
		cout << "Enter key";
		cin >> key;
		it = nums.lower_bound(key);//ищет первое вхождение ключа и возвращает итератор
		it1 = nums.upper_bound(key);//ищет последнее вхождение ключа и возвращает итератор
		//если первое вхождение ключа не найдено - выходим
		if (it == nums.end())
		{
			cout << "No such key\n";
			return 0;
		}
		std::copy(it, it1, std::ostream_iterator<std::pair<int, string>>(cout, " "));
	}
	break;
	case 3:
	{
		vector<int> nums(10);
		std::for_each(nums.begin(), nums.end(), [&nums](int& i)
		{
			nums.insert(nums.begin(), 100 + rand() % 10000);
		});

		nums.resize(10);//устанавливает фиксированный размер
		nums.shrink_to_fit();//выделяет память под размер

		std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(cout, " "));
		cout << endl;
		//bind позволяет изменять количество аргументов и сами аргументы функтора
		//или функции
		//placeholders определяет на какую позицию из параметров функции 
		//greater(в данном случае) поставим 5000
		std::copy_if(nums.begin(), nums.end(), std::ostream_iterator<int>(cout, " "),
			std::bind(std::greater<int>(), std::placeholders::_2, 5000));
	}
	}


	return 0;
}