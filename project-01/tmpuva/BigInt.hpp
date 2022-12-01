#pragma once

#include <bits/stdc++.h>

class BigInt
{

    friend std::ostream &operator<<(std::ostream &out, const BigInt &x);
    friend bool operator==(const BigInt &a, const BigInt &b);
    friend bool operator!=(const BigInt &a, const BigInt &b);
    friend bool operator>=(const BigInt &a, const BigInt &b);
    friend bool operator<=(const BigInt &a, const BigInt &b);
    friend bool operator<(const BigInt &a, const BigInt &b);
    friend BigInt operator+(const BigInt &x, const BigInt &y);
    friend BigInt operator-(const BigInt &x, const BigInt &y);

    static int CompValue(const BigInt &a, const BigInt &b)
    {
        if (a.mDigits.size() > b.mDigits.size())
            return 1;
        if (a.mDigits.size() < b.mDigits.size())
            return -1;
        for (size_t i = 0; i < a.mDigits.size(); i++)
        {
            if (a.mDigits[i] != b.mDigits[i])
            {
                return a.mDigits[i] - b.mDigits[i];
            }
        }
        return 0;
    }

    static int cmpAbsValues(const BigInt &x, const BigInt &y)
    {
        if (x.mDigits.size() < y.mDigits.size())
        {
            return -1;
        }
        if (x.mDigits.size() > y.mDigits.size())
        {
            return 1;
        }

        for (size_t i = 0; i < x.mDigits.size(); ++i)
        {
            if (x.mDigits[i] != y.mDigits[i])
            {
                return x.mDigits[i] - y.mDigits[i];
            }
        }

        return 0;
    }

    static BigInt subAbsValues(const BigInt &x, const BigInt &y)
    {
        auto itX = x.mDigits.rbegin();

        BigInt z;
        z.mDigits.resize(x.mDigits.size());
        auto itZ = z.mDigits.rbegin();

        int borrow = 0;
        for (auto itY = y.mDigits.rbegin(); itY != y.mDigits.rend();)
        {
            int d = *itX - borrow - *itX;
            if (x < 0)
            {
                d += 10;
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }
            *itZ = d;
        }

        for (; borrow != 0; ++itX, ++itZ)
        {
            int d = *itX - borrow;
            if (d < 0)
            {
                d += 10;
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }
            *itZ = d;
        }

        z.eraseLeadingZero();
        return z;
    }

    void eraseLeadingZero()
    {
        auto it = mDigits.begin();
        while (it + 1 != mDigits.end() && *it == 0)
        {
            ++it;
        }
        mDigits.erase(mDigits.begin(), it);
    }

    std::vector<int> mDigits;
    bool mIsNegative;

public:
    BigInt()
        : mIsNegative(false)
    {

        mDigits.push_back(0);
    }

    BigInt(const std::string &value)
        : mIsNegative(false)
    {
        if (value.empty())
        {
            throw std::runtime_error("BigInt : empty string");
        }
        size_t i = 0;
        if (!value.empty() && (value[i] == '-' || value[i] == '+'))
        {
            mIsNegative = value[i] == '-';
            i++;
        }

        while (i + 1 < value.size() && value[i] == '0')
        {
            ++i;
        }

        for (; i < value.size() && isdigit(value[i]); i++)
        {
            mDigits.push_back(value[i] - '0');
        }
        if (i < value.size() || mDigits.empty())
        {
            throw std::runtime_error("BigInt: Incorrect string representation");
        }
        if (mDigits.size() == 1 && mDigits[0] == 0)
            mIsNegative = false;
    }

    BigInt(long long x)

        : BigInt(std::to_string(x))
    {
    }

    static BigInt addAbsValues(const BigInt &x, const BigInt &y)
    {
        auto itX = x.mDigits.rbegin();
        auto itY = y.mDigits.rbegin();

        BigInt z;
        z.mDigits.resize(std::max(x.mDigits.size(), y.mDigits.size()) + 1);
        auto itZ = z.mDigits.rbegin();

        int carry = 0;
        while (itX != x.mDigits.rend() || itY != y.mDigits.rend())
        {
            int s = carry;
            if (itX != x.mDigits.rend())
            {
                s += *itX;
                itX++;
            }
            if (itY != y.mDigits.rend())
            {
                s += *itY;
                itY++;
            }
            *itZ = s % 10;
            carry = (s > 9) ? 1 : 0;
            itZ++;
        }
        if (carry != 0)
            *itZ = carry;
        if (z.mDigits.size() > 1 && z.mDigits.front() == 0)
            z.mDigits.erase(z.mDigits.begin());
        return z;
    }
};

inline std::ostream &operator<<(std::ostream &out, const BigInt &x)
{
    if (x.mIsNegative)
        out << "-";

    for (auto e : x.mDigits)
    {
        out << e;
    }

    return out;
}

inline std::istream &operator>>(std::istream &inp, BigInt &x)
{
    char ch;
    if (!(inp >> ch))
    {
        return inp;
    }

    if (!(std::isdigit(ch) || ch == '+' || ch == '-'))
    {
        inp.putback(ch);
        inp.setstate(std::ios_base::failbit);
        return inp;
    }

    std::string s;
    s += ch;

    while (inp.get(ch) && std::isdigit(ch))
    {
        s += ch;
    }

    if (s.size() == 1 && (s[0] == '+' || s[0] == '-'))
    {
        inp.setstate(std::ios_base::failbit);
        return inp;
    }

    x = BigInt(s);

    return inp;
}

inline bool operator<(const BigInt &a, const BigInt &b)
{
    if (a.mIsNegative && !(b.mIsNegative))
        return true;
    if (!(a.mIsNegative) && b.mIsNegative)
        return false;
    if (!(a.mIsNegative) && !(b.mIsNegative))
        return (BigInt::CompValue(a, b) < 0);

    return (BigInt::CompValue(a, b) > 0);
}

bool operator==(const BigInt &a, const BigInt &b)
{
    return a.mIsNegative == b.mIsNegative && a.mDigits == b.mDigits;
}

bool operator!=(const BigInt &a, const BigInt &b)
{
    return !(a == b);
}

inline bool operator<=(const BigInt &a, const BigInt &b)
{
    return !(b < a);
}

inline bool operator>=(const BigInt &a, const BigInt &b)
{
    return !(a < b);
}

inline bool operator>(const BigInt &a, const BigInt &b)
{
    if (a == b)
    {
        return false;
    }
    return !(a < b);
}

inline BigInt operator+(const BigInt &x, const BigInt &y)
{
    if (!x.mIsNegative && !y.mIsNegative)
        return BigInt::addAbsValues(x, y);
    int cmp = BigInt::cmpAbsValues(x, y);
    if (cmp == 0)
        return BigInt();
    if (cmp > 0)
    {
        BigInt r = BigInt::subAbsValues(x, y);
        r.mIsNegative = x.mIsNegative;
        return r;
    }
    else if (cmp < 0)
    {
        BigInt r = BigInt::subAbsValues(y, x);
        r.mIsNegative = y.mIsNegative;
        return r;
    }
    return BigInt();

    throw std::runtime_error("not implemented yet");
}

inline BigInt operator-(const BigInt &x, const BigInt &y)
{
    if (!x.mIsNegative && y.mIsNegative)
        return BigInt::addAbsValues(x, y);

    if (x.mIsNegative && !y.mIsNegative)
    {
        BigInt r = BigInt::addAbsValues(x, y);
        r.mIsNegative = true;
        return r;
    }
    if (!x.mIsNegative && !y.mIsNegative)
    {
        int cmp = BigInt::cmpAbsValues(x, y);
        if (cmp >= 0)
        {
            return BigInt::subAbsValues(x, y);
        }
    }
    throw std::runtime_error("not implemented yet");
}