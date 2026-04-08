#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        multiset<int> left, right;
        long long sumLeft = 0;
        for (int i = 1; i <= dist + 1; i++) {
            left.insert(nums[i]);
            sumLeft += nums[i];
        }

        while (left.size() > k - 1) {
            auto it = prev(left.end());
            sumLeft -= *it;
            right.insert(*it);
            left.erase(it);
        }

        long long ans = sumLeft;

        for (int i = dist + 2; i < nums.size(); i++) {
            int out = nums[i - dist - 1];
            int in = nums[i];

            // remove outgoing
            if (left.count(out)) {
                left.erase(left.find(out));
                sumLeft -= out;
            } else {
                right.erase(right.find(out));
            }

            if (!left.empty() && in < *left.rbegin()) {
                left.insert(in);
                sumLeft += in;
            } else {
                right.insert(in);
            }

            while (left.size() < k - 1) {
                auto it = right.begin();
                sumLeft += *it;
                left.insert(*it);
                right.erase(it);
            }

            while (left.size() > k - 1) {
                auto it = prev(left.end());
                sumLeft -= *it;
                right.insert(*it);
                left.erase(it);
            }

            ans = min(ans, sumLeft);
        }

        return nums[0] + ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,3,2,6,4,2};
    int k = 3, dist = 3;

    cout << sol.minimumCost(nums, k, dist) << endl;
}
