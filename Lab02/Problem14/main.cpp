
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

bool Check(vector<int> numbers) {
    int Ordered = 0;
for(int i = 0; i < sz(numbers); i++) {

    if(i == 9) break;
    if(numbers[i] > numbers[i + 1] || (numbers[i] < numbers[i + 1] && numbers[i + 1] < numbers[i + 2])) Ordered++;
    if(numbers[i] > numbers[i + 1] && numbers[i + 1] < numbers[i + 2]) return false;

    }

    return Ordered > 6; 
}

int main()
{
    iostream::sync_with_stdio(false);

    int numTestCase;
    cin >> numTestCase;
    cout << "Lumberjacks:" << '\n';
    for(int i = 0; i < numTestCase; i++) {

        vector<int> numbers;
        int num;

        for(int j = 0; j < 10; j++) {
            cin >> num;
            numbers.push_back(num);
        }

        if(Check(numbers)) cout << "Ordered" << '\n';
        else cout << "Unordered" << '\n';
        
    }
}