
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int firstChannel, secondChannel;

    int firstResult;
    int secondResult;
    while (cin >> firstChannel >> secondChannel) {
        if (firstChannel && secondChannel == -1) break;
        if(firstChannel  > secondChannel) {
            int temp = firstChannel;
            firstChannel = secondChannel;
            secondChannel = temp;
        }

        firstResult = secondChannel - firstChannel;
        secondResult  = 100 - secondChannel + firstChannel ;
        cout << min(firstResult,secondResult) << endl;
    }

}