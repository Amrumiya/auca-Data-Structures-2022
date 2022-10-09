
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

int people;
    cin >> people;

    vector<string> NumOfPeople(people);
    for (auto &e: NumOfPeople) {
        cin >> e;
    }
    vector<bool> Checker(people);
    vector<string> messages(16);
    string birthday = " Happy birthday to you! Happy birthday to you! Happy birthday to Rujia! Happy birthday to you!!!";

    int j = 0;
    stringstream ssin(birthday);
    while (ssin.good() && j < 16) {
        ssin >> messages[j];
        ++j;
    }

    
    Checker[0] = true;
    for (int i = 1; i <= (int) messages.size(); i++) {
        if (i % 2 != 0) {
            if (Checker[0]) {
                cout << NumOfPeople[0] << messages[i] << '\n';
                Checker[0] = false;
                Checker[2] = true;
                Checker[1] = true;
            } else if (Checker[2]) {
                cout << NumOfPeople[2]<< ": " << messages[i] << '\n';
                Checker[2] = false;
                Checker[0] = true;
            }
        }
        if (i % 2 == 0 && Checker[1]) {cout << NumOfPeople[1] << ": " << messages[i] << '\n'; Checker[1] = false; }
    }
}   