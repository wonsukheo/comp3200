#include "MyString.h"

namespace assignment1
{
	MyString::MyString(const char* s)
	{
		if (s == nullptr)
		{
			mLength = 0;
			mCapacity = INITIAL_CAPACITY;
			mCString = nullptr;
			return;
		}

		mLength = MyStrLen(s);

		mCapacity = mLength + 1;

		mCString = new char[mCapacity];

		MyStrCpy(mCString, s);
	}

	MyString::MyString(const MyString& other)
		: mLength(other.mLength)
		, mCapacity(other.mCapacity)
	{
		mCString = new char[mCapacity];

		MyStrCpy(mCString, other.mCString);
	}

	MyString::~MyString()
	{
		delete[] mCString;
	}

	unsigned int MyString::GetLength() const
	{
		return mLength;
	}

	const char* MyString::GetCString() const
	{
		return mCString;
	}

	void MyString::Append(const char* s)
	{
		if (s == nullptr || MyStrCmp(s, ""))
		{
			return;
		}

		unsigned int length = MyStrLen(s);

		if (mLength + length >= mCapacity)
		{
			mCapacity += length;

			char* temp = new char[mCapacity];

			MyStrCpy(temp, mCString);

			delete[] mCString;

			mCString = temp;
		}

		MyStrCat(s);

		mLength += length;
	}

	MyString MyString::operator+(const MyString& other) const
	{
		MyString temp = *this;

		temp.Append(other.mCString);

		return temp;
	}

	int MyString::IndexOf(const char* s)
	{
		if (s == "")
		{
			return 0;
		}

		if (s == nullptr)
		{
			return -1;
		}

		const char* p1 = mCString;
		const char* p2 = s;

		while (*p1 != '\0')
		{
			if (*p1 == *p2)
			{
				const char* pp1 = p1 + 1;
				const char* pp2 = p2 + 1;
				bool bSame = true;

				while (*pp2 != '\0')
				{
					if (*pp1++ != *pp2++)
					{
						bSame = false;
						break;
					}
				}

				if (bSame)
				{
					return p1 - mCString;
				}
			}

			++p1;
		}

		return -1;
	}

	int MyString::LastIndexOf(const char* s)
	{
		unsigned int length = MyStrLen(s);

		if (s == "")
		{
			return mLength;
		}

		if (mLength == 0)
		{
			return -1;
		}

		const char* p1 = mCString + mLength - 1;
		const char* p2 = s + length - 1;

		while (p1 != mCString)
		{
			if (*p1 == *p2)
			{
				const char* pp1 = p1;
				const char* pp2 = p2;
				bool bSame = true;

				while (pp2 != s)
				{
					if (*pp1-- != *pp2--)
					{
						bSame = false;
						break;
					}
				}

				if (bSame)
				{
					return p1 - (length - 1) - mCString;
				}
			}

			--p1;
		}

		return -1;
	}

	void MyString::Interleave(const char* s)
	{
		if (s == "" || nullptr)
		{
			return;
		}

		unsigned int length = MyStrLen(s);

		char* result = new char[mLength + length + 1];

		char* resultPtr = result;
		const char* p1 = mCString;
		const char* p2 = s;

		while (true)
		{
			if (*p1 == '\0' && *p2 == '\0')
			{
				break;
			}

			if (*p1 != '\0')
			{
				*resultPtr++ = *p1++;
			}

			if (*p2 != '\0')
			{
				*resultPtr++ = *p2++;
			}
		}

		*resultPtr = '\0';

		if (mLength + length >= mCapacity)
		{
			mCapacity = (mLength + length) * 2;
		}

		delete[] mCString;

		mCString = result;

		mLength += length;
	}

	bool MyString::RemoveAt(unsigned int i)
	{
		if (i >= mLength)
		{
			return false;
		}

		char* p = mCString + i;

		while (*p != '\0')
		{
			*p = *(p + 1);

			++p;
		}

		mLength -= 1;

		return true;
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
		if (totalLength > mLength)
		{
			if (totalLength >= mCapacity)
			{
				mCapacity += totalLength;

				char* temp = new char[mCapacity];

				MyStrCpy(temp, mCString);

				delete[] mCString;

				mCString = temp;
			}

			char* p = mCString + mLength;
			char* pp = mCString + totalLength;

			while (true)
			{
				*pp-- = *p--;

				if (p == mCString)
				{
					*pp = *p;

					break;
				}
			}

			while (mLength != totalLength)
			{
				*p++ = ' ';

				++mLength;
			}
		}
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
		if (totalLength > mLength)
		{
			if (totalLength >= mCapacity)
			{
				mCapacity += totalLength;

				char* temp = new char[mCapacity];

				MyStrCpy(temp, mCString);

				delete[] mCString;

				mCString = temp;
			}

			char* p = mCString + mLength;
			char* pp = mCString + totalLength;

			while (true)
			{
				*pp-- = *p--;

				if (p == mCString)
				{
					*pp = *p;

					break;
				}
			}

			while (mLength != totalLength)
			{
				*p++ = c;

				++mLength;
			}
		}
	}

	void MyString::PadRight(unsigned int totalLength)
	{
		if (totalLength > mLength)
		{
			if (totalLength >= mCapacity)
			{
				mCapacity += totalLength;

				char* temp = new char[mCapacity];

				MyStrCpy(temp, mCString);

				delete[] mCString;

				mCString = temp;
			}

			char* p = mCString + mLength;

			while (mLength != totalLength)
			{
				*p++ = ' ';

				mLength++;
			}

			*p = '\0';
		}
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
		if (totalLength > mLength)
		{
			if (totalLength >= mCapacity)
			{
				mCapacity += totalLength;

				char* temp = new char[mCapacity];

				MyStrCpy(temp, mCString);

				delete[] mCString;

				mCString = temp;
			}

			char* p = mCString + mLength;

			while (mLength != totalLength)
			{
				*p++ = c;

				mLength++;
			}

			*p = '\0';
		}
	}

	void MyString::Reverse()
	{
		if (mLength < 2)
		{
			return;
		}

		char* p = mCString;
		char* pp = mCString + mLength - 1;

		while (p < pp)
		{
			char temp = *p;
			*p = *pp;
			*pp = temp;

			++p;
			--pp;
		}
	}

	bool MyString::operator==(const MyString& rhs) const
	{
		if (mCString == nullptr || rhs.mCString == nullptr)
		{
			return false;
		}

		return MyStrCmp(mCString, rhs.mCString);
	}

	MyString& MyString::operator=(const MyString& rhs)
	{
		if (*this == rhs) 
		{
			return *this;
		}

		mLength = rhs.mLength;
		mCapacity = rhs.mCapacity;

		delete[] mCString;

		mCString = new char[mCapacity];

		MyStrCpy(mCString, rhs.mCString);

		return *this;
	}

	void MyString::ToLower()
	{
		char* p = mCString;

		while (*p != '\0')
		{
			if (IsAlpha(*p))
			{
				*p |= 32;
			}

			++p;
		}
	}

	void MyString::ToUpper()
	{
		char* p = mCString;

		while (*p != '\0')
		{
			if (IsAlpha(*p))
			{
				*p &= ~32;
			}

			++p;
		}
	}

	bool MyString::IsAlpha(const char c)
	{
		return (c >= 65 && c <= 90 || c >= 97 && c <= 122) ? true : false;
	}

	bool MyString::MyStrCmp(const char* str1, const char* str2) const
	{
		const char* p1 = str1;
		const char* p2 = str2;

		while (*p1 == *p2 && *p1 != '\0')
		{
			++p1;
			++p2;
		}

		return (*p2 == '\0') ? true : false;
	}

	unsigned int MyString::MyStrLen(const char* str)
	{
		const char* p;

		p = str;

		while (*p++ != '\0')
		{
		}

		return p - str - 1;
	}

	void MyString::MyStrCpy(char* dest, const char* src)
	{
		char* destPtr = dest;
		const char* srcPtr = src;

		while (true)
		{
			*destPtr++ = *srcPtr;

			if (*srcPtr++ == '\0')
			{
				break;
			}
		}
	}

	void MyString::MyStrCat(const char* s)
	{
		char* p = mCString + mLength;

		MyStrCpy(p, s);
	}
}