// 习题1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <ctime>

using std::vector;
using std::fstream;
using std::endl;
using std::cout;

void generate(int);
void sort_1();
void sort_2();

int _tmain(int argc, _TCHAR* argv[])
{
	generate(500000);
	clock_t start, finish;
	start = clock();
	//sort_1();
	sort_2();
	finish = clock();
	cout << finish - start<< endl;
	system("PAUSE");
	return 0;
}

void generate(int num)
{
	vector<int> need_sort_num;
	need_sort_num.reserve(num);
	for (int i = 0; i < num; ++i)
	{
		need_sort_num.push_back(num-i);
	}
	fstream file(".\\need_sort_num.txt",fstream::out);
	for each (auto  var in need_sort_num)
	{
		file << var << endl;
	}
	file.close();
}

void sort_1()
{
	vector<int> need_sort_num;
	int var;
	fstream file(".\\need_sort_num.txt", fstream::in);
	while (file >> var)
	{
		need_sort_num.push_back(var);
	}
	file.close();
	std::sort(need_sort_num.begin(), need_sort_num.end());
	fstream file2(".\\need_sort_num.txt", fstream::out);
	for each (auto var in need_sort_num)
	{
		file2 << var << endl;
	}
	file2.close();
}
void sort_2()
{
	vector<unsigned int> bit_vec;
	bit_vec.resize(500000/32+1,0);
	int var,i;
	unsigned int tmp;
	fstream file(".\\need_sort_num.txt", fstream::in);
	while (file >> var)
	{
		tmp = (unsigned int)1 << var % 32;
		bit_vec[var / 32] = bit_vec[var / 32] | tmp;
	}

	fstream file2(".\\need_sort_num.txt", fstream::out);
	int size = bit_vec.size();
	for (auto j = 0; j <size ;++j)
	{
		for (i = 0; i < 32; ++i)
		{
			tmp = (unsigned int)1 << i;
			if (!(var & tmp))
			{
				file2 << j*32 + i<<endl;
			}

		}
	}



}