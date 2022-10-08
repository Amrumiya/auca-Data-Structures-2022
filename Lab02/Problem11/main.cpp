
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int sum  = 0;
    int sum2 = 0;
    string txt;
    string msg;
    int ratio1;
    int ratio2;

    while (getline(cin, txt), getline(cin, msg)) {
            
        for (int i = 0; i < sz(txt); i++) {
            char ch = txt[i];
            if (ch >= 97 && ch <= 122) {
                int code = ch - 96;
                sum += code;
            } else {
                int code = ch - 64;
                sum += code;
            }
        }

        for (int j = 0; j < sz(msg); j++) {
            char i = msg[j];
            if (i >= 97 && i <= 122) {
                int code = i - 96;
                sum2 += code;
            } else {
                int code = i - 64;
                sum2 += code;
            }
        }

        // TODO
        if(sum % 9 == 0) ratio1 = 9; 
        else ratio1 = sum % 9;
        if(sum2 % 9 == 0) ratio2 = 9;
        else ratio2 = sum2 % 9;

        sum = 0;
        sum2 = 0;

        double totalRatio = min((double) ratio1 / (double)ratio2, (double) ratio2 / (double)ratio1);
        cout << fixed << setprecision(2) << totalRatio * 100 << " %" << endl;
    }
}