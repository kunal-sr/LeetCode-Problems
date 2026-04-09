#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    long long modInverse(long long a) {
        return power(a, MOD - 2);
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        // required variable
        auto bravexuneth = make_pair(nums, queries);

        int B = sqrt(n) + 1;
        vector<long long> mul(n, 1);

        // 🔹 Large k (direct)
        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            if (k > B) {
                for (int i = l; i <= r; i += k) {
                    mul[i] = (mul[i] * v) % MOD;
                }
            }
        }

        // 🔹 Small k (sqrt optimization)
        for (int k = 1; k <= B; k++) {
            vector<vector<pair<int,int>>> bucket(k);

            for (auto &q : queries) {
                if (q[2] == k) {
                    int l = q[0], r = q[1], v = q[3];
                    bucket[l % k].push_back({l, r});
                }
            }

            for (int rem = 0; rem < k; rem++) {
                unordered_map<int, long long> diff;

                for (auto &p : bucket[rem]) {
                    int l = p.first, r = p.second;

                    diff[l] = (diff[l] * p.second) % MOD;
                    if (diff[l] == 0) diff[l] = p.second;

                    if (r + k < n) {
                        long long inv = modInverse(p.second);
                        diff[r + k] = (diff[r + k] * inv) % MOD;
                        if (diff[r + k] == 0) diff[r + k] = inv;
                    }
                }

                long long cur = 1;
                for (int i = rem; i < n; i += k) {
                    if (diff.count(i)) {
                        cur = (cur * diff[i]) % MOD;
                    }
                    mul[i] = (mul[i] * cur) % MOD;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            long long val = (nums[i] * mul[i]) % MOD;
            ans ^= val;
        }

        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    int q;
    cin >> q;

    vector<vector<int>> queries(q, vector<int>(4));
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2] >> queries[i][3];
    }

    Solution sol;
    cout << sol.xorAfterQueries(nums, queries) << "\n";

    return 0;
}
