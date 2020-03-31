#pragma once

#include <iostream>
#include <vector>
#include <map>

namespace lab7
{
	template <typename K, class V>
	std::map<K, V> ConvertVectorsToMap(const std::vector<K>& keys, const std::vector<V>& values)
	{
		std::map<K, V> m;
		for (unsigned int i = 0; i < keys.size() && i < values.size(); i++)
		{
			m.insert(std::pair<K, V>(keys.at(i), values.at(i)));
		}
		
		return m;
	}

	template <typename K, class V>
	std::vector<K> GetKeys(const std::map<K, V>& m)
	{
		std::vector<K> v;
		for (auto it = m.begin(); it != m.end(); it++)
		{
			v.push_back(it->first);
		}
		return v;
	}

	template <typename K, class V>
	std::vector<V> GetValues(const std::map<K, V>& m)
	{
		std::vector<V> v;
		for (auto it = m.begin(); it != m.end(); it++)
		{
			v.push_back(it->second);
		}
		return v;
	}

	template <typename T>
	std::vector<T> Reverse(const std::vector<T>& v)
	{
		std::vector<T> rv;
		for (auto it = v.rbegin(); it != v.rend(); it++)
		{
			rv.push_back(*it);
		}

		return rv;
	}

	template <typename T>
	std::vector<T> operator+(const std::vector<T>& v1, const std::vector<T>& v2)
	{
		/*std::map<T, int> tmp;
		std::vector<T> combined;
		for (auto it = v1.begin(); it != v1.end(); it++)
		{
			tmp.insert(std::pair<T, int>(*it, 0));
		}

		for (auto it = v2.begin(); it != v2.end(); it++)
		{
			tmp.insert(std::pair<T, int>(*it, 0));
		}

		for (auto it = tmp.begin(); it != tmp.end(); it++)
		{
			combined.push_back(it->first);
		}*/

		std::vector<T> combined;
		for (auto it = v1.begin(); it != v1.end(); it++)
		{
			if (find(combined.begin(), combined.end(), *it) == combined.end())
			{
				combined.push_back(*it);
			}
		}

		for (auto it = v2.begin(); it != v2.end(); it++)
		{
			if (find(combined.begin(), combined.end(), *it) == combined.end())
			{
				combined.push_back(*it);
			}
		}


		return combined;
	}

	template <typename K, class V>
	std::map<K, V> operator+(const std::map<K, V>& m1, const std::map<K, V>& m2)
	{
		std::map<K, V> combined;
		for (auto it = m1.begin(); it != m1.end(); it++)
		{
			combined.insert(*it);
		}

		for (auto it = m2.begin(); it != m2.end(); it++)
		{
			combined.insert(*it);
		}
		return combined;
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
	{
		for (auto it = v.begin(); it != v.end(); it++)
		{
			if (it != v.end() - 1)
			{
				os << *it << ", ";
			}
			else
			{
				os << *it;
			}
		}
		return os;
	}

	template <typename K, class V>
	std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m)
	{
		for (auto it = m.begin(); it != m.end(); it++)
		{
			os << "{ " << it->first << ", " << it->second << " }\n";
		}
		return os;
	}
}