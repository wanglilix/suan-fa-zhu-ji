// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#define num 100000

int q_sort_k(int[], int, int, int);

int _tmain(int argc, _TCHAR* argv[])
{
	int vec[num];
	int k = 2201;
	for (auto i = 0; i < num; ++i)
		vec[i] = rand();
	auto k_ = q_sort_k(vec, k, 0, num - 1);

	return 0;
}

int q_sort_k(int vec[], int k ,int begin, int end)
{
	int l = begin;
	int r = end;
	int x = vec[begin];

	while (l<r)
	{
		while (vec[r] > x &&  l<r)
			--r;
		if (l < r)
			vec[l++] = vec[r];
		while (vec[l] <= x && l < r)
			++l;
		if (l < r)
			vec[r--] = vec[l];
	}

	vec[l] = x;
	if (l == k)
		return x;
	else if (l > k)
		return q_sort_k(vec, k, begin, l - 1);
	else if (l < k)
		return q_sort_k(vec,k,l+1,end);


}