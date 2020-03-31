#include "Person.h"

namespace assignment2
{
	Person::Person()
		:	mWeight(0)
	{
	}
	Person::Person(const char* name, unsigned int weight)
		:   mWeight(weight),
			mName(name)
	{
	}

	Person::~Person()
	{
	}

	const std::string& Person::GetName() const
	{
		return mName;   
	}

	const char* Person::GetName2() const
	{
		char* c = const_cast<char*>(mName.c_str());
		return c;
	}

	unsigned int Person::GetWeight() const
	{
		return mWeight;
	}
}