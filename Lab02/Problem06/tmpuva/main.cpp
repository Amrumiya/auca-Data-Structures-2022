
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
    for (int i = 0; i < numTestCase; i++) {
        while (cin >> firstSalary >> secondSalary >> thirdSalary) {
            
            string first = to_string(firstSalary);
            string second = to_string(secondSalary);
            string third = to_string(thirdSalary);

            int average = (firstSalary + secondSalary + thirdSalary) / 3;
            if(average != firstSalary && average != secondSalary && average && thirdSalary) {
                string av = to_string(average);
                if (av[0] == first[0]) average = firstSalary;
                else if(av[0] == second[0])  average = secondSalary;
                else average = thirdSalary;
            }
            cout << average << '\n';
        }
    }

}