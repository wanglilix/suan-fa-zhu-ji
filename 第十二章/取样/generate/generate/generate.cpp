// generate.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <set>

using std::set;

void create(int,int);
void create_2(int, int);
int _tmain(int argc, _TCHAR* argv[])
{
	//create(100,20000);
	create_2(100,20000);
	return 0;
}

void create(int m, int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (rand() % (n - i) < m)
		{
			std::cout << i << std::endl;
			--m;
		}
			
	}
}

void create_2(int m, int n)
{

	set<int> set_;
	while (set_.size()<m)
		set_.insert(rand()%n);

	for each (auto var in set_)
		std::cout << var << std::endl;
}