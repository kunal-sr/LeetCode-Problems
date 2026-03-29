#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        unordered_set<int> primes = {2,3,5,7,11,13,17,19};

        int count = 0;

        for (int i = left; i <= right; i++) {
            int bits = __builtin_popcount(i);

            if (primes.count(bits)) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    Solution sol;

    int left = 6, right = 10;

    cout << sol.countPrimeSetBits(left, right) << endl;

    return 0;
}
