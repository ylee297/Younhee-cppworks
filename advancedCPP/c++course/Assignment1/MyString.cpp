#include "MyString.h"


namespace assignment1
{

	MyString::MyString(const char* s)
	{
		mSizeOfString = 0;

		for (int i = 0; s[i] != '\0'; i++)
		{
			mSizeOfString++;
		}
		mString = new char[mSizeOfString + 1];

		for (unsigned int i = 0; i < mSizeOfString; i++)
		{
			mString[i] = s[i];
		}
		mString[mSizeOfString] = '\0';

	}

	MyString::MyString(const MyString& other)
		: mSizeOfString(other.mSizeOfString)
	{
		mString = new char[mSizeOfString + 1];
		for (unsigned int i = 0; i < mSizeOfString; i++)
		{
			mString[i] = other.mString[i];
		}
		mString[mSizeOfString] = '\0';
	}

	MyString::~MyString()
	{
		delete []mString;
	}

	unsigned int MyString::GetLength() const
	{
		return mSizeOfString;
	}

	const char* MyString::GetCString() const
	{
		return mString;
	}

	void MyString::Append(const char* s)
	{
		int size = 0;
		for (int i = 0; s[i] != '\0'; i++)
		{
			size++;
		}

		if (size == 0)
		{
			return;
		}

		char* tmp;
		tmp = mString;

		mString = new char[mSizeOfString + size + 1];

		for (int i = 0; tmp[i] != '\0'; i++)
		{
			mString[i] = tmp[i];
		}
		for (int i = 0; s[i] != '\0'; i++)
		{
			mString[mSizeOfString + i] = s[i];
		}
		mString[mSizeOfString + size] = '\0';

		delete []tmp;
		mSizeOfString += size;
	}

	MyString MyString::operator+(const MyString& other) const
	{
		assignment1::MyString temp(mString);
		temp.Append(other.mString);

		return temp;
	}

	int MyString::IndexOf(const char* s)
	{
		int iStart = 0;
		int size = 0;
		bool bCheck = true;
		while (mString[iStart] != '\0')
		{
			size++;
			for (int i = 0; s[i] != '\0'; i++)
			{
				if (mString[iStart + i] != s[i])
				{
					bCheck = false;
				}
				if (bCheck == false)
				{
					iStart++;
					break;
				}
			}
			if (bCheck == true)
			{
				return iStart;
			}
			bCheck = true;
		}

		if (mSizeOfString == 0 && *s == '\0')
		{
			return 0;
		}

		return -1;
	}

	int MyString::LastIndexOf(const char* s)
	{
		int index = -1;
		int iStart = 0;
		bool bCheck = true;
		while (mString[iStart] != '\0')
		{
			for (int i = 0; s[i] != '\0'; i++)
			{
				if (mString[iStart + i] != s[i])
				{
					bCheck = false;
				}
				if (bCheck == false)
				{
					iStart++;
					break;
				}
			}
			if (bCheck == true)
			{
				index = iStart;
				iStart++;
			}
			bCheck = true;
		}

		if (*s == '\0')
		{
			return mSizeOfString;
		}

		return index;
	}

	void MyString::Interleave(const char* s)
	{
		unsigned int cIndex = 0;
		unsigned int pIndex = 0;
		unsigned int mStringIndex = 0;

		unsigned int size = 0;
		for (int i = 0; s[i] != '\0'; i++)
		{
			size++;
		}

		if (size == 0)
		{
			return;
		}

		char* tmp = mString;
		mString = new char[mSizeOfString + size + 1];

		while (tmp[cIndex] != '\0' || s[pIndex] != '\0')
		{
			if (tmp[cIndex] != '\0')
			{
				mString[mStringIndex] = tmp[cIndex];
				cIndex++;
				mStringIndex++;
			}

			if (s[pIndex] != '\0')
			{
				mString[mStringIndex] = s[pIndex];
				pIndex++;
				mStringIndex++;
			}
		}
		delete []tmp;

		mString[mSizeOfString + size] = '\0';
		mSizeOfString += size;
	}

	bool MyString::RemoveAt(unsigned int index)
	{
		if (index >= mSizeOfString)
		{
			return false;
		}

		bool bExist = false;
		char* tmp = mString;
		mString = new char[mSizeOfString];

		int mIndex = 0;
		int tmpIndex = 0;
		for (unsigned int i = 0; i < mSizeOfString; i++)
		{
			if (tmpIndex != index)
			{
				mString[mIndex] = tmp[tmpIndex];
				mIndex++;
			}
			else
			{
				bExist = true;
			}
			tmpIndex++;
		}


		mSizeOfString--;
		mString[mSizeOfString] = '\0';
		delete []tmp;

		return bExist;
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
		if (totalLength <= mSizeOfString)
		{
			return;
		}

		unsigned int numOfSpace = totalLength - mSizeOfString;
		char* tmp = mString;
		mString = new char[totalLength + 1];

		for (unsigned int i = 0; i < numOfSpace; i++)
		{
			mString[i] = ' ';
		}
		for (unsigned int i = 0; i < totalLength - numOfSpace; i++)
		{
			mString[i + numOfSpace] = tmp[i];
		}
		mString[totalLength] = '\0';


		delete []tmp;
		mSizeOfString = totalLength;
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
		if (totalLength <= mSizeOfString)
		{
			return;
		}

		unsigned int numOfSpace = totalLength - mSizeOfString;
		char* tmp = mString;
		mString = new char[totalLength + 1];

		for (unsigned int i = 0; i < numOfSpace; i++)
		{
			mString[i] = c;
		}
		for (unsigned int i = 0; i < totalLength - numOfSpace; i++)
		{
			mString[i + numOfSpace] = tmp[i];
		}
		mString[totalLength] = '\0';


		delete []tmp;
		mSizeOfString = totalLength;

	}

	void MyString::PadRight(unsigned int totalLength)
	{
		if (totalLength <= mSizeOfString)
		{
			return;
		}

		unsigned int numOfSpace = totalLength - mSizeOfString;

		char* tmp = mString;
		mString = new char[totalLength + 1];

		for (unsigned int i = 0; i < mSizeOfString; i++)
		{
			mString[i] = tmp[i];
		}
		for (unsigned int i = 0; i < numOfSpace; i++)
		{
			mString[mSizeOfString + i] = ' ';
		}
		mString[totalLength] = '\0';

		mSizeOfString = totalLength;
		delete []tmp;
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
		if (totalLength <= mSizeOfString)
		{
			return;
		}

		unsigned int numOfSpace = totalLength - mSizeOfString;

		char* tmp = mString;
		mString = new char[totalLength + 1];

		for (unsigned int i = 0; i < mSizeOfString; i++)
		{
			mString[i] = tmp[i];
		}
		for (unsigned int i = 0; i < numOfSpace; i++)
		{
			mString[mSizeOfString + i] = c;
		}
		mString[totalLength] = '\0';

		mSizeOfString = totalLength;
		delete []tmp;
	}

	void MyString::Reverse()
	{
		for (unsigned int i = 0, j = mSizeOfString - 1; i < (mSizeOfString / 2); i++, j--)
		{
			char temp = mString[i];
			mString[i] = mString[j];
			mString[j] = temp;
		}
	}

	bool MyString::operator==(const MyString& rhs) const
	{
		bool bResult = true;
		if (mSizeOfString != rhs.mSizeOfString)
		{
			return false;
		}

		for (unsigned int i = 0; i < mSizeOfString; i++)
		{
			if (mString[i] != rhs.GetCString()[i])
			{
				bResult = false;
				break;
			}
		}

		return bResult;
	}

	MyString& MyString::operator=(const MyString& rhs)
	{
		if (this != &rhs)
		{
			mSizeOfString = rhs.mSizeOfString;

			delete[]mString;
			mString = new char[mSizeOfString + 1];

			for (unsigned int i = 0; i < mSizeOfString; i++)
			{
				mString[i] = rhs.mString[i];
			}

			mString[mSizeOfString] = '\0';
		}
		return *this;
	}

	void MyString::ToLower()
	{
		for (unsigned int i = 0; i < mSizeOfString; i++)
		{
			if (mString[i] <= 90 && mString[i] >= 65)
			{
				mString[i] += 32;
			}
		}
	}

	void MyString::ToUpper()
	{
		for (unsigned int i = 0; i < mSizeOfString; i++)
		{
			if (mString[i] >= 97 && mString[i] <= 122)
			{
				mString[i] -= 32;
			}
		}
	}
}