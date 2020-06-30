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
		set<string> riverBank = { "�������", "���" };
		set<string> riverDepth = { "�����", "�����", "�����" };

		set<string> all;
		//����������� ������� ���� ���������� � �������� � all
		std::set_union(riverBank.begin(), riverBank.end(), riverDepth.begin(),
			riverDepth.end(), inserter(all, all.begin()));
		cout << "Union:\n";
		std::copy(all.begin(), all.end(), std::ostream_iterator<string>(cout, " "));
		cout << endl;

		//����������� ������� ����� ��� riverBank � riverDepth �������
		cout << "Intersection:\n";
		std::set_intersection(riverBank.begin(), riverBank.end(), riverDepth.begin(),
			riverDepth.end(), std::ostream_iterator<string>(cout, " "));
		cout << endl;

		//��������� ������� ������� �������� ������ ������ ���������, �� �� �������
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
		{ 1, "����" },
		{ 1, "����" },
		{ 1, "one" },
		{ 2, "���" },
		{ 2, "two" },
		{ 3, "���" },
		{ 3, "���" },
		{ 3, "three" },
		{ 4, "������" },
		{ 4, "������" },
		{ 4, "four" } };

		//it - ���������� � multimap ��������
		multimap<int, string>::iterator it, it1;
		int key;
		cout << "Enter key";
		cin >> key;
		it = nums.lower_bound(key);//���� ������ ��������� ����� � ���������� ��������
		it1 = nums.upper_bound(key);//���� ��������� ��������� ����� � ���������� ��������
		//���� ������ ��������� ����� �� ������� - �������
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

		nums.resize(10);//������������� ������������� ������
		nums.shrink_to_fit();//�������� ������ ��� ������

		std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(cout, " "));
		cout << endl;
		//bind ��������� �������� ���������� ���������� � ���� ��������� ��������
		//��� �������
		//placeholders ���������� �� ����� ������� �� ���������� ������� 
		//greater(� ������ ������) �������� 5000
		std::copy_if(nums.begin(), nums.end(), std::ostream_iterator<int>(cout, " "),
			std::bind(std::greater<int>(), std::placeholders::_2, 5000));
	}
	}


	return 0;
}