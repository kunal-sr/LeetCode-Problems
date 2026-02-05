#include <iostream>
using namespace std;

int climbStairs(int n) {
    if (n == 1) {
        return 1;
    }

    int dp[46];   // since n <= 45

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Enter number of steps: ";
    cin >> n;

    int result = climbStairs(n);
    cout << "Number of ways to climb: " << result << endl;

    return 0;
}