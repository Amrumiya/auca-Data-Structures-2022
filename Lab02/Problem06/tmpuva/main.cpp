
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int numTestCase;
    cin >> numTestCase;

    int firstSalary, secondSalary, thirdSalary;
    int Arr[3];
    int incrementer = 1;
    while (numTestCase != 0) {
        cin >> firstSalary >> secondSalary >> thirdSalary;
        Arr[0] = firstSalary;
        Arr[1] = secondSalary;
        Arr[2] = thirdSalary;
        sort(begin(Arr), end(Arr));
        cout << "Case " << incrementer++ << ": " << Arr[1] << '\n';
        numTestCase--;

    }
}