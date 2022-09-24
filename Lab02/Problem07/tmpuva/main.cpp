
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int firstChannel, secondChannel;

    int result;
    while (cin >> firstChannel >> secondChannel) {
        if (firstChannel && secondChannel == -1) break;
        if(firstChannel == 0) {
            firstChannel = 100;
            result = firstChannel - secondChannel;
        }
        else {
             result = secondChannel - firstChannel;
        }
        cout << result << endl;
    }

}