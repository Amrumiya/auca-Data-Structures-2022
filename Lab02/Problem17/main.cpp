
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;



int main()
{
    iostream::sync_with_stdio(false);


    int firstNum, secondNum;
    char g[150][150];

    while (scanf("%d%d", &firstNum, &secondNum) == 2) {
        for (int i = 0; i < firstNum; ++i) scanf("%s", g[i]);
        int Answer = 0;
        for (int i = 0; i < firstNum; ++i) {
            bool Checker = false;
            for (int j = 0; j < secondNum; ++j) {
                if (g[i][j] == '/' || g[i][j] == '\\') {
                    ++Answer;
                    Checker = !Checker;
                } else if (Checker) Answer += 2;
            }
        }
        cout << Answer / 2 << '\n';
    }
}



