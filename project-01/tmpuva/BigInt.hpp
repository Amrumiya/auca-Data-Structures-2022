#pragma once

#include <bits/stdc++.h>

class BigInt
{
   friend std::ostream &operator<<(std::ostream &out, const BigInt &x);
   friend bool operator==(const BigInt &a, const BigInt &b);
   friend bool operator!=(const BigInt &a, const BigInt &b);
   friend bool operator>=(const BigInt &a, const BigInt &b);
   friend bool operator<=(const BigInt &a, const BigInt &b);
   friend bool operator>(const BigInt &a, const BigInt &b);

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
            if(value.empty())
            {
                throw std::runtime_error("BigInt : empty string");
            }
            size_t i = 0;
            if(value[i] == '-' || value[i] == '+')
            {
                mIsNegative = value[i] == '-';
                i++;
            }

            while(i + 1 != value.size() && value[i] == '0')
            {
                ++i;
            }

            for(; i != value.size(); i++)
            {
                if(!isdigit(value[i]))
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
    if(a == b)
    {
        return false;
    }
    return !(a < b);
}