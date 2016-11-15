// search.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include "assert.h"

#define NDEBUG


using std::vector;
int search(int[100],int,int,int);

int _tmain(int argc, _TCHAR* argv[])
{
	int vec[100];
	for (int i = 0; i < 100; ++i)
		vec[i] = i*2;
	int num = 99*2;
	assert(search(vec, 0, 99, 99*2) == 99 );
	assert(search(vec, 0, 99, 0) == 0 );
	assert(search(vec, 0, 99, 1) == -1 );

	return 0;
}

int search(int vec[100],int start,int end, int num)
{
	if (start>end)
	{
		return -1;
	}else if (start == end)
	{
		if (vec[start] == num)
			return start;
		else
			return -1;
	}else if (start+1 == end)
	{
		if (vec[start] == num)
			return start;
		else if (vec[end] == num)
			return end;
		else
			return -1;
	}
	else
	{
		int center = (start + end) / 2;
		if (vec[center] < num )
		{
			return search(vec,center,end,num);
		}
		else if (vec[center] > num)
		{
			return search(vec, start, center, num);
		}
		else
		{
			return center;
		}

	}
}
