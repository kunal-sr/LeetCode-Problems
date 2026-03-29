#include <bits/stdc++.h>
using namespace std;

bool hasAlternatingBits(int n) {
    int x = n ^ (n >> 1);
    return (x & (x + 1)) == 0;
}

int main() {
    int n = 5;
    if (hasAlternatingBits(n))
        cout << "True\n";
    else
        cout << "False\n";
    return 0;
}
