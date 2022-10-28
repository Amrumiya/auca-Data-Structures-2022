#pragma once

template<typename T>

class Rational 
{

T mNum; // data member, field 
T mDen;


public:
    Rational() 
        : mNum(0), mDen(1)
        {
            
        }

        Rational(const T &num, const T &den) {
            : mNum(num), mDen(den);



        }
    
   const T &num() const
    {
        return mNum;
    }

    const  T &den() const 
    {
        return mDen;
    }
};


template <typename T>
std::ostream &operator<<(std::ostream &out, const Rational<T> &x)
{
    out << x.num() << "/ " << x.den();
    return out;
}


