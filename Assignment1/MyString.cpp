#include "MyString.h"

namespace assignment1
{
    MyString::MyString(const char* s)
    {
        unsigned int length = MyStrLen(s);

        mLength = length;

        mCapacity = mLength >= INITIAL_CAPACITY ? mLength * 2 : INITIAL_CAPACITY;

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
        unsigned int length = MyStrLen(s);

        if (mLength + length >= mCapacity)
        {
            mCapacity = (mLength + length) * 2;

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

        const char* p1 = mCString + mLength;
        const char* p2 = s + length;

        while (p1 != mCString)
        {
            if (*p1 == *p2)
            {
                const char* pp1 = p1 - 1;
                const char* pp2 = p2 - 1;
                bool bSame = true;

                while (pp2 != s)
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

            --p1;
        }

        return -1;
    }

    void MyString::Interleave(const char* s)
    {
        unsigned int length = MyStrLen(s);

        if (mLength + length >= mCapacity)
        {
            mCapacity = (mLength + length) * 2;

            char* temp = new char[mCapacity];

            MyStrCpy(temp, mCString);

            delete[] mCString;

            mCString = temp;
        }

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

            while (p != mCString)
            {
                *pp-- = *p--;
            }

            while (p - mCString != totalLength - mLength)
            {
                *p++ = ' ';
            }

            mLength = totalLength;
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

            while (p != mCString)
            {
                *pp-- = *p--;
            }

            while (p - mCString != totalLength - mLength)
            {
                *p++ = c;
            }

            mLength = totalLength;
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

            while (p - mCString == totalLength)
            {
                *p++ = ' ';
            }

            *p = '\0';

            mLength = totalLength;
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

            while (p - mCString == totalLength)
            {
                *p++ = c;
            }

            *p = '\0';

            mLength = totalLength;
        }
    }

    void MyString::Reverse()
    {
        char* p = mCString;
        char* pp = mCString + mLength - 1;

        while (p != pp)
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
        return false;
    }

    MyString& MyString::operator=(const MyString& rhs)
    {
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

    bool IsAlpha(const char c)
    {
        return (c >= 65 && c <= 90 || c >= 97 && c <= 122) ? true : false;
    }

    bool MyStrCmp(const char* str1, const char* str2)
    {
        const char* p1 = str1;
        const char* p2 = str2;

        while (*p1 == *p2 && *p1 != '\0')
        {
            ++p1;
            ++p2;
        }

        return *p1 == '\0' ? true : false;
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
        char* dest_p = dest;
        const char* src_p = src;

        while (true)
        {
            *dest_p++ = *src_p;

            if (*src_p++ == '\0')
            {
                break;
            }
        }
    }

    void MyString::MyStrNCpy(char* dest, const char* src, unsigned int count)
    {
        char* dest_p = dest;
        const char* src_p = src;

        while (count--)
        {
            *dest_p++ = *src_p;
        }

        *dest_p == '\0';
    }

    void MyString::MyStrCat(const char* s)
    {
        char* p = mCString + mLength;

        MyStrCpy(p, s);
    }
}