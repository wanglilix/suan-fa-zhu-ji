				
// �������ȶ���.cpp : �������̨Ӧ�ó������ڵ㡣
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
//////������ȶ���
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
//////��С���ȶ���
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
//////����
	int a[] = { 15, 1, 12, 30, 20 };
	vector<int> vec(a, a + 5);
	make_heap(vec.begin(),vec.end());//����
	showvec(vec);

	pop_heap(vec.begin(), vec.end());//�������
	auto max = vec.back();
	vec.pop_back();
	showvec(vec);

	vec.push_back(max);
	push_heap(vec.begin(),vec.end());//������ֵ
	showvec(vec);

	sort_heap(vec.begin(),vec.end());//������
	showvec(vec);

//////��С��
	vector<int> vec_(a, a + 5);
	make_heap(vec_.begin(), vec_.end(), greater<int>());//����
	showvec(vec_);

	pop_heap(vec_.begin(), vec_.end(),greater<int>());//�������
	auto min = vec_.back();
	vec_.pop_back();
	showvec(vec_);

	vec_.push_back(min);
	push_heap(vec_.begin(), vec_.end(), greater<int>());//������ֵ
	showvec(vec_);

	sort_heap(vec_.begin(), vec_.end(),greater<int>());//������
	showvec(vec_);

	return 0;
}

