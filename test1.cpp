#include "bits/stdc++.h"
using namespace std;

int main () {
    stack <int> s1;
    s1.push(5);
    s1.push(10);
    s1.push(15);

    stack <int> s2;
    s2 = s1;

    cout << s2.top() << endl;
}