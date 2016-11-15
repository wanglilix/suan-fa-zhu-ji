// 堆.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using std::vector;

class Dui{  //要在使用之前对类声明，成员数据和成员函数都要声明，但定义可以在后面
private:
	vector<double> vec;
	int N;

	int leftchild(int i) { return i * 2; }
	int rightchild(int i){ return i * 2 + 1; }
	int parent(int i) { return i / 2; }
	bool exist(int i){ return i >= 1 && i <= N; }
	void shiftup(int k);
	void shiftdown(int k);
public:
	void insert(int k);
	int extractmin();
	Dui() :N(0){ vec.push_back(0); };

};

int _tmain(int argc, _TCHAR* argv[])
{
	Dui dui;
	dui.insert(12);
	dui.insert(20);
	dui.insert(15);
	dui.insert(11);


	auto var = dui.extractmin();
	var = dui.extractmin();
	var = dui.extractmin();

	return 0;
}


void Dui::insert(int k)
{
	shiftup(k);
}
void Dui::shiftup(int k)
{
	vec.push_back(k);
	++N;
	int i = N;
	while (i > 1 && vec[i] < vec[parent(i)])
	{
		double tmp = vec[parent(i)];
		vec[parent(i)] = vec[i];
		vec[i] = tmp;
		i = parent(i);
	}
}

void Dui::shiftdown(int k)
{
	int i (1);
	vec[1] = k;
	while (i <= N )
	{
		if ( exist(leftchild(i)) && vec[i] > vec[leftchild(i)])
		{
			double tmp = vec[leftchild(i)];
			vec[leftchild(i)] = vec[i];
			vec[i] = tmp;
			i = leftchild(i);
		}
		else if (exist(rightchild(i)) && vec[i] > vec[rightchild(i)])
		{
			double tmp = vec[rightchild(i)];
			vec[rightchild(i)] = vec[i];
			vec[i] = tmp;
			i = rightchild(i);
		}
		else
			break;
	}

}


int Dui::extractmin()
{
	if ( N < 1)
		return 0;
	int min = vec[1];
	vec[1] = vec[N];
	vec.erase(vec.end()-1);
	N--;
	if ( N < 1 )
		return min;
	shiftdown(vec[1]);
	return min;
}