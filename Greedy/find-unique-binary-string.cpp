#include <bits/stdc++.h>
using namespace std;

string findDifferentBinaryString(vector<string>& nums) {
    int n = nums.size();
    string result = "";

    for (int i = 0; i < n; i++) {

        if (nums[i][i] == '0')
            result += '1';
        else
            result += '0';
    }

    return result;
}

int main() {
    vector<string> nums = {"01", "10"};
    cout << findDifferentBinaryString(nums) << endl;
    return 0;
}
