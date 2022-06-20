#include "myString.h"

#include <cstring>
#include <iostream>

namespace myString
{
	myString::myString(const char* str)
	{
		unsigned int sLen = strlen(str);

		mSize = sLen;
		mCapacity = sLen * 2;

		mC_str = static_cast<char*>(malloc(sizeof(char) * mSize + 1));

		memcpy(mC_str, str, sizeof(char) * mSize + 1);
	}

	myString::myString(myString& other)
		: mSize(other.mSize)
		, mCapacity(other.mCapacity)
	{
		mC_str = static_cast<char*>(malloc(sizeof(char) * mSize + 1));

		memcpy(mC_str, other.mC_str, sizeof(char) * mSize + 1);
	}

	myString::~myString()
	{
		delete mC_str;
	}

	myString& myString::operator=(const myString& other)
	{
		mSize = other.mSize;
		mCapacity = other.mCapacity;

		delete mC_str;

		mC_str = static_cast<char*>(malloc(sizeof(char) * mSize + 1));

		memcpy(mC_str, other.mC_str, mSize + 1);

		return *this;
	}

	bool myString::operator==(const myString& other)
	{
		if (mSize != other.mSize)
		{
			return false;
		}

		if (strncmp(mC_str, other.mC_str, mSize) != 0)
		{
			return false;
		}

		return true;
	}

	myString& myString::operator+(const myString& other)
	{
		char* temp = mC_str;

		mC_str = static_cast<char*>(realloc(mC_str, mSize + other.mSize + 1));

		memcpy(mC_str + mSize, other.mC_str, other.mSize + 1);

		return *this;
	}

	char myString::operator[](unsigned int i)
	{
		if (i >= mSize)
		{
			return 0;
		}

		return *(mC_str + i);
	}
}