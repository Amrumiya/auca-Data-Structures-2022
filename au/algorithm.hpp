#pragma once
#include <utility>

template<typename T>
void auSwap(T &x, T &y)
{
    T t = std::move(x);
    x = std::move(y);
    y = std::move(t);
}



template<typename BidirectionalIter>
void auReverse(BidirectionalIter beg, BidirectionalIter end)
{
    for(;;)
    {
        if(beg == end) break;

        --end;

        if(beg == end)
        break;

        auSwap(*beg, *end);

        ++beg;
    }
}


template<typename ForwardIter, typename Key>
ForwardIter auFind(ForwardIter beg, ForwardIter end, const Key &key)
{
    for(; beg != end; ++beg)
    {
        if(*beg == key)
        {
            return beg;
        }
    }
    return beg;
}

template <typename ForwardIter, typename UnaryPredicate>
ForwardIter auFindIf(ForwardIter beg, ForwardIter end, UnaryPredicate pread)
{
    for(; beg != end; ++beg)
    {
        if(pread(*beg))
        {
            return beg;
        }
    }
    return beg;
}


template<typename Iter, typename Comp>
Iter auMinElement(Iter beg, Iter end, Comp comp)
{
    Iter min = beg;
    while (beg != end)
    {
      if (comp(*beg, *min))
      {
          min = beg;
      }
      beg++;
    }
    return min;
    
}