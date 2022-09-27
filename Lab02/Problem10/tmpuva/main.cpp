
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main() {
    int sum = 0;
    int sum2 = 0;
    string txt;
    string msg;
    int m = 1;
    int ratio1;
    int ratio2;
    while (cin >> txt) {
            cin >> msg;
        for (int i = 0; i < txt.length(); i++) {
            char ch = txt[i];
            if (ch >= 97 && ch <= 122) {
                int code = ch - 96;
                sum += code;
            } else {
                int code = ch - 64;
                sum += code;
            }
        }
//     //   char c = txt[0];
//      //  if (c >= 97 && c <= 122) {
//            for (int i = 0; i < txt.length(); i++) {
//                char d = txt[i];
//                int code = d - 96;
//                sum += code;
//            }
//        } else {
//            for (int i = 0; i < txt.length(); i++) {
//                char ch = txt[i];
//                int code = ch - 64;
//                sum += code;
//            }
//        }
        for (int j = 0; j < msg.length(); j++) {
            char i = msg[j];
            if (i >= 97 && i <= 122) {
                int code = i - 96;
                sum2 += code;
            } else {
                int code = i - 64;
                sum2 += code;
            }
        }
        ratio1 = (sum % 9 == 0) ? ratio1 = 9 : ratio1 = sum % 9;
        ratio2 = (sum2 % 9 == 0) ? ratio2 = 9 : ratio2 = sum2 % 9;
        sum = 0;
        sum2 = 0;

        double totalRatio = min((double) ratio1 / ratio2, (double) ratio2 / ratio1);
        printf("%.2f%\n", totalRatio * 100);
    }
}