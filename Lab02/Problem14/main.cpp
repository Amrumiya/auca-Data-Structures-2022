
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

bool Check(vector<int> numbers) {

//for(int i = 0; i < sz(numbers); i++) {
   //if(numbers[i] > numbers[i+1]);
   //else if(numbers[i] > numbers[i + 1] && numbers[i + 1] < numbers[ i + 2] ) return false;
   //else if(numbers[i] < numbers[i + 1]){};
   // }

   if(numbers[0] > numbers[1] && numbers[1] < numbers[2]) return false;

    return (numbers[0] > numbers[1] && numbers[1] > numbers[2] && numbers[2] > numbers[3]
   && numbers[3] > numbers[4] && numbers[4] > numbers[5] && numbers[5] > numbers[6]) || (numbers[0] < numbers[1] && 
   numbers[1] < numbers[2] && numbers[2] < numbers[3]
   && numbers[3] < numbers[4] && numbers[4] < numbers[5] && numbers[5] < numbers[6]); 
}

int main()
{
    iostream::sync_with_stdio(false);

    int numTestCase;
    cin >> numTestCase;
    cout << "Lumberjacks: " << '\n';
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