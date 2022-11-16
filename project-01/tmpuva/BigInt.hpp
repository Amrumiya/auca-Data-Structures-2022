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
        if (value[i] == '-' || value[i] == '+')
        {
            mIsNegative = value[i] == '-';
            i++;
        }

        while (i + 1 != value.size() && value[i] == '0')
        {
            ++i;
        }

        for (; i != value.size(); i++)
        {
            if (!isdigit(value[i]))
            {
                throw std::runtime_error("BigInt: Incorrect string value");
            }
            mDigits.push_back(value[i] - '0');
        }
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

inline bool operator<(const BigInt &a, const BigInt &b)
{
    if (a.mIsNegative && !(b.mIsNegative))
        return true;
    if (!(a.mIsNegative) && b.mIsNegative)
        return false;
    if (!(a.mIsNegative) && (b.mIsNegative))
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
inline bool operator<(const BigInt &a, const BigInt &b)
{
    return !(b < a);
}
