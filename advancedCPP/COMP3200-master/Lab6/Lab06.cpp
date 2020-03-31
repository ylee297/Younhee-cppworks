
#include "Lab6.h"

using namespace std;

namespace lab6
{
	int Sum(const std::vector<int>& v)
	{
		int sum = 0;
		for (auto it = v.begin(); it != v.end(); it++)
		{
			sum += *it;
		}
		return sum;
	}

	int Min(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return INT_MAX;
		}

		int min = v.at(0);
		for (auto it = v.begin() + 1; it != v.end(); it ++)
		{
			if (*it < min)
			{
				min = *it;
			}
		}
		return min;
	}

	int Max(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return INT_MIN;
		}

		int max = v.at(0);
		for (auto it = v.begin() + 1; it != v.end(); it ++)
		{
			if (*it > max)
			{
				max = *it;
			}
		}
		return max;
	}

	float Average(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return 0.0f;
		}

		float total = 0;
		for (auto it = v.begin(); it != v.end(); it++)
		{
			total += float(*it);
		}

		return (total / v.size());
	}

	int NumberWithMaxOccurrence(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return 0;
		}

		vector<int> tmp(v);
		SortDescending(tmp);

		int mostFreqNum = tmp[0];
		int mostFreq = 1;
		int freq = 1;
		int prev = tmp[0];

		for (unsigned int i = 1; i < tmp.size(); ++i)
		{
			if (prev == tmp[i])
			{
				freq++;
			}
			else
			{
				freq = 1;
			}

			if (freq > mostFreq)
			{
				mostFreq = freq;
				mostFreqNum = tmp[i];
			}

			prev = tmp[i];
		}

		tmp.clear();
		tmp.resize(0);
		return mostFreqNum;
	}

	void SortDescending(std::vector<int>& v)
	{
		MergeSort(v, 0, v.size() - 1);
	}

	std::vector<int> LeftVector;
	std::vector<int> RightVector;
	void Merge(std::vector<int>& v, int left, int median, int right)
	{

		int leftHalf = median - left + 1;
		int rightHalf = right - median;

		for (int i = 0; i < leftHalf; i++)
		{
			LeftVector.push_back(v[left + i]);
		}
		for (int i = 0; i < rightHalf; i++)
		{
			RightVector.push_back(v[median + 1 + i]);
		}

		int l = 0;
		int r = 0;
		int d = left;
		while (l < leftHalf && r < rightHalf)
		{
			if (LeftVector[l] >= RightVector[r])
			{
				v[d] = LeftVector[l];
				l++;
			}
			else
			{
				v[d] = RightVector[r];
				r++;
			}
			d++;
		}

		while (l < leftHalf)
		{
			v[d] = LeftVector[l];
			d++;
			l++;
		}

		while (r < rightHalf)
		{
			v[d] = RightVector[r];
			d++;
			r++;
		}

		LeftVector.clear();
		LeftVector.resize(0);
		RightVector.clear();
		RightVector.resize(0);
	}

	void MergeSort(std::vector<int>& v, int left, int right)
	{
		if (left < right)
		{
			int median = (left + right) / 2;
			MergeSort(v, left, median);
			MergeSort(v, median + 1, right);

			Merge(v, left, median, right);
		}
	}
}