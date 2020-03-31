#include <iostream>
#include <cassert>
#include "Lab6.h"

using namespace std;

int main()
{
	std::vector<int> v;
	v.push_back(-1);
	v.push_back(3);
	v.push_back(4);
	v.push_back(-1);
	v.push_back(7);
	v.push_back(-6);
	v.push_back(12);
	v.push_back(79);
	v.push_back(-50);
	v.push_back(-16);
	v.push_back(-50);
	v.push_back(-50);

	int sum = lab6::Sum(v);
	int max = lab6::Max(v);
	int min = lab6::Min(v);
	float average = lab6::Average(v);
	int numWithMaxOccurence = lab6::NumberWithMaxOccurrence(v);
	lab6::SortDescending(v);

	
	cout << numWithMaxOccurence << endl;

	for (int i = 0; i < (int)v.size() - 1; ++i)
	{
		assert(v[i] >= v[i + 1]);
	}

	return 0;
}