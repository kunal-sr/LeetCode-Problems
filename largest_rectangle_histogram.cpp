#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> st;        // stack to store indices
    int maxArea = 0;

    // add an extra bar of height 0 to process all bars
    heights.push_back(0);

    for (int i = 0; i < heights.size(); i++) {

        // while current bar is smaller than the bar at stack top
        while (!st.empty() && heights[st.top()] > heights[i]) {
            int height = heights[st.top()];
            st.pop();

            int width;
            if (st.empty()) {
                width = i;
            } else {
                width = i - st.top() - 1;
            }

            maxArea = max(maxArea, height * width);
        }

        st.push(i);
    }

    return maxArea;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    int result = largestRectangleArea(heights);

    cout << "Largest rectangle area: " << result << endl;

    return 0;
}