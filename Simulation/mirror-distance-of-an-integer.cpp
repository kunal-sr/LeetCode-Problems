#include <iostream>
#include <cmath>
using namespace std;

int mirrorDistance(int n) {
    int rev = 0;
    int temp = n;

    while (temp > 0) {
        int digit = temp % 10;
        rev = rev * 10 + digit;
        temp /= 10;
    }

    return abs(n - rev);
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

    cout << "Mirror Distance: " << mirrorDistance(n) << endl;

    return 0;
}
