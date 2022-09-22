#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {

    string name;
    cin >> name;


    int nGrades = 0;
    double sum = 0;
    int grade  = 0;
    while(cin >> grade) {
        ++nGrades;
        sum += grade;

    }

cout << setfill('.') << fixed << setprecision(2);

cout <<left << setw(30) << name << "|" << right << setw(30) << sum / nGrades << '\n';



}