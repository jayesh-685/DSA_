#include "bits/stdc++.h"
using namespace std;

int divByaAndB (int n, int a, int b) {
    // how many no are divisible by a and b between 1 and n
    int c1 = n/a;
    int c2 = n/b;
    int c3 = n/(a*b);
    
    return c1+c2-c3;
}

int EuclidGCD (int a, int b) {
    // if we want to calculate gcd of 42 and 24, it will be same as that of 18(42-24) and 24, which will be same as that of 18 and 6, then 12 and 6 then 6 and 6 so our answer is 6. We just keep on subtracting diff from the smaller no till we get 0
    // or we can just keep on taking modulo till it becomes 0

    while (b!=0) {
        int rem = a%b;
        a = b;
        b = rem;
        cout << a << " " << b << " " << rem << endl;
    }
    return a;
}

int main () {
    // int n, a, b;
    // cin >> n >> a >> b;
    // cout << divByaAndB(n, a, b) << endl;
    int a, b;
    cin >> a >> b;
    cout << EuclidGCD(a, b) << endl;

    return 0;
}