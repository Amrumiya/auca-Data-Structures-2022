
#include <bits/stdc++.h>


//template <typename C>
//int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

template <typename T >
void auSwap(T &a, T &b) {
    
    T t = a;
    a = b;
    b = t;

}


//pass by value 
void badSwap(int a, int b) {
    
 int t = a;
 a = b;
 b = t;

}

//pass by reference 
void goodSwap01(int &a, int &b) {

    int t = a;
    a = b;
    b = t;
}

void goodSwap01(int *pA, int *pB) {
    int t = *pA;
    *pA = *pB;
    *pB  = t;

}



int main()
{
    iostream::sync_with_stdio(false);

    cout << "1st int: ";
    int a;
    cin >> a;

    cout << "2nd int: ";
    int b;
    cin >> b;

    cout << "standart swap: " << endl;
    cout << "Before swap a = " << a << ", b = " << b << endl;
    swap(a,b);
    cout << "After swap a = " << a << ", b = " << b << endl;
    
    cout << "badSwap: " << endl;
    cout << "Before swap a = " << a << ", b = " << b << endl;
    badSwap(a,b);
    cout << "After swap a = " << a << ", b = " << b << endl;
    
    cout << "goodSwap01: " << endl;
    cout << "Before swap a = " << a << ", b = " << b << endl;
    goodSwap01(a,b);
    cout << "After swap a = " << a << ", b = " << b << endl;
    
    double d1 = 1.6;
    double d2 = 3.14;
    cout << "goodSwap01: ";
    cout << "Before swap a = " << a << ", b = " << b << endl;
    auSwap(d1, d2);
    cout << "After swap a = " << a << ", b = " << b << endl;
    
}