				
// 堆与优先队列.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <queue>
#include <functional>

using namespace std;

struct cmp{
	bool operator()(int & lhs, int & rhs){
		return lhs > rhs;
	}
};
void showvec(const vector<int> & vec)
{
	for each (auto var in vec)
		cout << var << endl;
	cout << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
//////最大优先队列
	priority_queue<int> q;
	//priority_queue<int, vector<int>, less<int>> _q;
	q.push(2);
	q.push(4);
	q.push(3);
	q.push(1);
	while (!q.empty())
	{
		cout<<q.top()<<endl;
		q.pop();
	}
	cout << endl;
//////最小优先队列
	priority_queue<int, vector<int>, greater<int>> _q;
	_q.push(2);
	_q.push(4);
	_q.push(3);
	_q.push(1);
	while (!_q.empty())
	{
		cout << _q.top() << endl;
		_q.pop();
	}
	cout << endl;
//////最大堆
	int a[] = { 15, 1, 12, 30, 20 };
	vector<int> vec(a, a + 5);
	make_heap(vec.begin(),vec.end());//建堆
	showvec(vec);

	pop_heap(vec.begin(), vec.end());//弹出最大
	auto max = vec.back();
	vec.pop_back();
	showvec(vec);

	vec.push_back(max);
	push_heap(vec.begin(),vec.end());//加入新值
	showvec(vec);

	sort_heap(vec.begin(),vec.end());//堆排序
	showvec(vec);

//////最小堆
	vector<int> vec_(a, a + 5);
	make_heap(vec_.begin(), vec_.end(), greater<int>());//建堆
	showvec(vec_);

	pop_heap(vec_.begin(), vec_.end(),greater<int>());//弹出最大
	auto min = vec_.back();
	vec_.pop_back();
	showvec(vec_);

	vec_.push_back(min);
	push_heap(vec_.begin(), vec_.end(), greater<int>());//加入新值
	showvec(vec_);

	sort_heap(vec_.begin(), vec_.end(),greater<int>());//堆排序
	showvec(vec_);

	return 0;
}

