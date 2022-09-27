#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    const string NoDataMessage = "no data";
    const int colomnWidth = 30;

    for(string name; cin >> name;) {

    int nGrades = 0;
    double sum = 0;
    int grade = 0;

    for (int grade; cin >> grade;) {
        ++nGrades;
        sum += grade;
    }
    // setfill()
    cout << setfill('.') << fixed << setprecision(2);
    if(nGrades != 0) {
    
    cout << left << setw(colomnWidth) << name << "|" << right << setw(colomnWidth) << sum / nGrades << '\n';
    
    } else {
        cout << left << setw(colomnWidth) << name << "|" << right << setw(colomnWidth) << NoDataMessage << '\n';
    }
    // fixed is
    cin.clear();
    }
}