#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int x) {

    // negative numbers are not palindrome
    if (x < 0) {
        return false;
    }

    int original = x;
    int reversed = 0;

    while (x > 0) {
        int digit = x % 10;
        reversed = reversed * 10 + digit;
        x = x / 10;
    }

    if (original == reversed) {
        return true;
    }

    return false;
}

int main() {
    int x;
    cout << "Enter a number: ";
    cin >> x;

    if (isPalindrome(x)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}