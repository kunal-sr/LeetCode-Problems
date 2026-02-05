#include <iostream>
using namespace std;

int mySqrt(int x) {
    if (x == 0) {
        return 0;
    }

    int left = 1;
    int right = x;
    int ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // use long long to prevent overflow
        long long square = (long long)mid * mid;

        if (square == x) {
            return mid;
        }
        else if (square < x) {
            ans = mid;        // store possible answer
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return ans;
}

int main() {
    int x;
    cout << "Enter a non-negative number: ";
    cin >> x;

    int result = mySqrt(x);
    cout << "Square root (rounded down) is: " << result << endl;

    return 0;
}