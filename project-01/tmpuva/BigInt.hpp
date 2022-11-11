#pragma once 

#include <bits/stdc++.h>


using namespace std;


class BigInt
{
    std::vector<int> mDigits;
    bool mIsNegative;
public:
      BigInt()
        : mIsNegative(false)
    {

        mDigits.push_back(0);
    }


};
std::ostream &operator<<(std::ostream &out, const BigInt &x)
{
    BigInt out;
    return out;
}
