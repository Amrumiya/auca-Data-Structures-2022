
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main() {
    int NumTestCase;
    cin >> NumTestCase;
    for (int k = 1; k <= NumTestCase; k++) {
        int Num;
        cin >> Num;

        int ArrWall[50];
        for (int i = 0; i < Num; i++)
            cin >> ArrWall[i];

        int LeftIncrement = 0, RightIncrement = 0;
        for (int i = 0; i < Num - 1; i++) {
            if (ArrWall[i + 1] < ArrWall[i])
                RightIncrement++;
            if (ArrWall[i + 1] > ArrWall[i])

                LeftIncrement++;
        }
        cout << "Case " << k << ": " << LeftIncrement << " " << RightIncrement << endl;

    }


    }
