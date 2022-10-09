
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

     int n, m;
    char g[120][120];
    while (scanf("%d%d", &n, &m) == 2) {
        for (int i = 0; i < n; i++) scanf("%s", g[i]);

        int answer = 0;
        for (int i = 0; i < n; i++) {
            bool checker = false;
            for (int j = 0; j < m; j++) {
                if (g[i][j] == '/' || g[i][j] == '\\') {
                    answer++;
                    checker = !checker;
                } else if (checker) answer += 2;
            }
            int FinalAnswer = answer / 2;
            cout << FinalAnswer << '\n';

        }
    }
}



