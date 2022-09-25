
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int sum = 0;
    int sum2 = 0;
    string txt;
    string msg;
    int m = 1;
    while (m != 0) {
        cin >> txt >> msg;
        char c = txt[0];
        if (c >= 97 && c <= 122) {
            for (int i = 0; i < txt.length(); i++) {
                char d = txt[i];
                int code = d - 96;
                sum += code;
            }
        } else {
            for (int i = 0; i < txt.length(); i++) {
                char ch = txt[i];
                int code = ch - 64;
                sum += code;
            }
        }
        for (int j = 0; j < msg.length(); j++) {
            char i = msg[j];
            if (i >= 97 && i <= 122) {
                int code = i - 96;
                sum2 += code;
            } else {
                int code = i - 96;
                sum2 += code;
            }
        }
        double add =(double) (sum / 10) + (sum % 10);
        double  add2 = (double) (sum2 / 10) + (sum2 % 10);
        printf("%f\n", (add / add2) * 100);
        cin >> m;
    }
}