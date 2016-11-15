// 最长重复字符串.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <set>
#include <algorithm>

using std::string;
using std::set;
using std::set;
using std::vector;
using std::istringstream;

int _tmain(int argc, _TCHAR* argv[])
{
	string str_1("ask not what your country can do for you , but what you can do for your country can do");
	string str_word;
	string str_tmp;
	string str_max;
	int max_length(0);
	vector<string> str_vec;
	set<string> str_set;
	istringstream in_str(str_1);
	while (in_str >> str_word)
		str_vec.push_back(str_word);
	for (auto i = str_vec.begin(); i != str_vec.end(); ++i)
	{
		str_tmp.clear();
		for (auto j = i; j != str_vec.end(); j++)
			str_tmp += *j;
		str_set.insert(str_tmp);
	}
	auto i = str_set.begin();
	i++; if (i == str_set.end()) return 0;
	i++; if (i == str_set.end()) return 0;//寻找出现3次的最长字符串
	for (; i != str_set.end(); ++i)
	{
		auto tmp_1 = *(--(--i));
		auto tmp_2 = *(++(++i));
		int size = std::min(tmp_1.size(), tmp_2.size());
		for (auto j = 0; j < size; ++j)
		{
			if (tmp_1[j] != tmp_2[j])
			{
				if (j>max_length)
				{
					max_length = j;
					str_max = tmp_1.substr(0, j);
				}
				break;
			}
			if (j == size-1)
			{
				if (j>max_length)
				{
					max_length = j;
					str_max = tmp_1;
				}
			}
		}
	}


	return 0;
}

