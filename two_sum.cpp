#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {2, 7, 11, 15};   // input array
    int target = 9;                      // target value

    unordered_map<int, int> mp;          // number -> index

    for (int i = 0; i < nums.size(); i++) {
        int need = target - nums[i];

        // if the required number is already present
        if (mp.find(need) != mp.end()) {
            cout << mp[need] << " " << i << endl;
            return 0;
        }

        // store current number with its index
        mp[nums[i]] = i;
    }

    return 0;
}
