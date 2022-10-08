
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;



int main()
{
    iostream::sync_with_stdio(false);

    int numTestCase;
    cin >> numTestCase;
    cout << "Lumberjacks: " << endl;
    for(int i = 0; i < numTestCase; i++) {

        vector<int> numbers (10);
    

        for(int j = 0; j < 10; j++) {
            cin >> numbers[j];
        }

        for(int j = 0; j < sz(numbers) - 1; j++) {

                if(numbers[j] > numbers[j + 1]) {
        
                    reverse(numbers.begin(), numbers.end());
                }
        }
        
        int Sorted = is_sorted(begin(numbers), end(numbers));

        cout << (Sorted == 1 ? "Ordered\n" : "Unordered\n");
    }
}