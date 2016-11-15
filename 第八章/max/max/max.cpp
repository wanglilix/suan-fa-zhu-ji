// max.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#define num 100000

using std::vector;

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> vec;
	vec.resize(num, 0);
	for (int i = 0; i < num; ++i)
		vec[i] = rand()-20000;

	vector<int> vec_max;
	vec_max.resize(num,0);

	vec_max[0] = vec[0] > 0 ? vec[0] : 0;
	for (int i = 1; i < num; ++i)
		vec_max[i] = (vec_max[i - 1] + vec[i]) > 0 ? (vec_max[i - 1] + vec[i]) : 0 ;

	int max = *std::max_element(vec_max.begin(),vec_max.end());

	return 0;
}

