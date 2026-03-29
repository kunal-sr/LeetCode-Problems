#include <bits/stdc++.h>
using namespace std;

long long maxUnits(long long t, long long T) {

    long long val = (2 * T) / t;
    long long k = (sqrt(1 + 4 * val) - 1) / 2;
    return k;
}

long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
    long long left = 1, right = 1e18;
    long long ans = right;

    while (left <= right) {
        long long mid = (left + right) / 2;

        long long total = 0;

        for (int t : workerTimes) {
            total += maxUnits(t, mid);
            if (total >= mountainHeight) break;
        }

        if (total >= mountainHeight) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}

int main() {
    int mountainHeight = 10;
    vector<int> workerTimes = {1, 2, 3};

    cout << "Minimum seconds: "
         << minNumberOfSeconds(mountainHeight, workerTimes) << endl;

    return 0;
}
