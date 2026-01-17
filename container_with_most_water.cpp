#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;

    int maxWater = 0;

    while (left < right) {
        int width = right - left;
        int currentHeight = min(height[left], height[right]);
        int currentArea = width * currentHeight;

        maxWater = max(maxWater, currentArea);

        // move the pointer with smaller height
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxWater;
}

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    int result = maxArea(height);

    cout << "Maximum water container can store: " << result << endl;

    return 0;
}