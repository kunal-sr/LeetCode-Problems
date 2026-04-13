#include <bits/stdc++.h>
using namespace std;

int getMinDistance(vector<int>& nums, int target, int start) {
    int minDist = INT_MAX;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            minDist = min(minDist, abs(i - start));
        }
    }

    return minDist;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target, start;
    cout << "Enter target: ";
    cin >> target;
    cout << "Enter start index: ";
    cin >> start;

    int result = getMinDistance(nums, target, start);

    cout << "Minimum Distance: " << result << endl;

    return 0;
}
