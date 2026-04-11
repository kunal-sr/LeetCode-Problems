#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        
        int ans = INT_MAX;
        
        for (auto &it : mp) {
            vector<int> &v = it.second;
            
            if (v.size() >= 3) {
                int i = v.front();
                int k = v.back();
                
                ans = min(ans, 2 * (k - i));
            }
        }
        
        return (ans == INT_MAX) ? -1 : ans;
    }
};
