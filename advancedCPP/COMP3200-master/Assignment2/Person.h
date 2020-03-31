#pragma once

#include <string>

using namespace std;

namespace assignment2
{
	class Person
	{
	public:
		Person();
		Person(const char* name, unsigned int weight);
		~Person();

		const std::string& GetName() const;
		const char* GetName2() const;
		unsigned int GetWeight() const;

	private:
		string mName;
		unsigned int mWeight;
	};
}