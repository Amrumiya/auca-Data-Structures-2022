#include <bits/stdc++.h>

using namespace std;

int main() {

int road, integ;
int devisor;
int increment = 1;
while(cin >> road >> integ) {

    if((road && integ) == 0) break;
    road --;
    devisor = road / integ;
    
    
    if(devisor > 26) { 
        cout << "Case " << increment <<": " << "impossible\n";
        increment++;
        }
    else { cout << "Case " << increment <<": "  << devisor << '\n';
        increment++;
         }
    }
}