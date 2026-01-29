#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();

    // start from the last digit
    for (int i = n - 1; i >= 0; i--) {

        // if digit is less than 9, just add 1
        if (digits[i] < 9) {
            digits[i]++;
            return digits;
        }

        // if digit is 9, make it 0
        digits[i] = 0;
    }

    // if all digits were 9, add 1 at the front
    digits.insert(digits.begin(), 1);

    return digits;
}

int main() {
    vector<int> digits = {9, 9, 9};

    vector<int> result = plusOne(digits);

    cout << "Result: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}