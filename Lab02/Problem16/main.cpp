
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

    vector<string> messages(16);
    string birthday = " Happy birthday to you! Happy birthday to you! Happy birthday to Rujia! Happy birthday to you!!!";

    int j = 0;
    stringstream ssin(birthday);
    while (ssin.good() && j < 16) {
        ssin >> messages[j];
        ++j;
    }
     int person = 0;
    int word = 0;
    bool isDone;
    for (;;) {
        cout << messages[person] << ": " << messages[word] << "\n";
         if (person == people - 1) {
            isDone = true;
        }

        if (word == (int) messages.size() - 1 && isDone) {
            break;
        }

        ++person;
        ++word;

        if (person == people) {
            person = 0;
        }
        if (word == (int) messages.size()) {
            word = 0;
        }
    }


    return 0;
}   