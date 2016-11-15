// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#define num 100000

void q_sort_(int[], int, int);

int _tmain(int argc, _TCHAR* argv[])
{
	int vec[num];
	for (auto i = 0; i < num; ++i)
		vec[i] = rand();
	q_sort_(vec, 0, num - 1);


	return 0;
}

void q_sort_(int vec[], int begin, int end)
{
	if (begin >= end)
		return;
	int l = begin;
	int r = end;
	int x = vec[begin];//l已经转移

	while (l < r)
	{
		//l已经转移
		while (l < r && vec[r] > x)
			--r;
		//assert(vec[r] >= x || l == r)
		if (l < r)
			vec[l++] = vec[r];
		//r已经转移
		while (l < r && vec[l] <= x)
			++l;
		//assert(vec[rl] < x || l == r)
		if (l < r)
			vec[r--] = vec[l];
	}
	//l == r
	vec[l] = x;
	q_sort_(vec, begin, l - 1);
	q_sort_(vec, l + 1, end);
}