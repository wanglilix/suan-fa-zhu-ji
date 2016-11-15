// 第三题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>

using std::vector;

void turn_1(vector<int>& , int);
void turn_2(vector<int>& , int);

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> vec;
	for (auto i = 0; i < 12; ++i)
		vec.push_back(i);

	//turn_1(vec,3);

	turn_2(vec,2);

	return 0;
}

void turn_1(vector<int>& vec,int k)
{
	int tmp, j, size_, break_(0);
	size_ = vec.size();

	for (auto i = 0; i < k; ++i)
	{
		tmp = vec[i];
		j = i + k;
		while (!( j%size_ == i))
		{
			vec[(j - k)%size_] = vec[j%size_];//重点
			j += k;
			++break_;
			if (break_ == size_)
			{
				break;
			}
		}
		vec[(j - k) % size_] = tmp;
		++break_;
		if (break_ == size_)//重点
		{
			break;
		}
	}
}
void swap_(vector<int>::iterator iter_1,vector<int>::iterator iter_2)
{
	int tmp(0);
	if (iter_1 != iter_2)
	{
		tmp = *iter_2;
		*iter_2 = *iter_1;
		*iter_1 = tmp;
		iter_1++;
		iter_2--;
	}

	while ((iter_1 != iter_2) && (iter_1-1 != iter_2))
	{
		tmp = *iter_2;
		*iter_2 = *iter_1;
		*iter_1 = tmp;
		iter_1++;
		iter_2--;
	}
}
void turn_2(vector<int>& vec, int k)
{
	swap_(vec.begin(),vec.begin()+k);
	swap_(vec.begin()+k+1,vec.end()-1);
	swap_(vec.begin(),vec.end()-1);
}