#include <bits/stdc++.h>
using namespace std;

long long maxTrionicSum(vector<int>& nums) {
    int n = nums.size();

    vector<long long> incL(n), dec(n), incR(n);

    incL[0] = nums[0];
    for (int i = 1; i < n; i++) {
        if (nums[i] > nums[i - 1])
            incL[i] = incL[i - 1] + nums[i];
        else
            incL[i] = nums[i];
    }

    dec[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] > nums[i + 1])
            dec[i] = dec[i + 1] + nums[i];
        else
            dec[i] = nums[i];
    }

    incR[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1])
            incR[i] = incR[i + 1] + nums[i];
        else
            incR[i] = nums[i];
    }

    long long ans = LLONG_MIN;

    for (int p = 1; p < n - 2; p++) {

        if (!(nums[p - 1] < nums[p] && nums[p] > nums[p + 1])) continue;

        for (int q = p + 1; q < n - 1; q++) {

            if (!(nums[q - 1] > nums[q] && nums[q] < nums[q + 1])) continue;

            long long sum = incL[p] + dec[p] + incR[q] - nums[p] - nums[q];
            ans = max(ans, sum);
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {0,-2,-1,-3,0,2,-1};
    cout << maxTrionicSum(nums) << endl;
    return 0;
}
