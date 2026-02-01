#include <bits/stdc++.h>
using namespace std;

// Function to calculate largest rectangle in histogram
int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0;

    // add an extra bar of height 0
    heights.push_back(0);

    for (int i = 0; i < heights.size(); i++) {
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

// Function to find maximal rectangle of 1s
int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.size() == 0) return 0;

    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int> heights(cols, 0);
    int maxRectangle = 0;

    for (int i = 0; i < rows; i++) {
        // build histogram for this row
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '1') {
                heights[j]++;
            } else {
                heights[j] = 0;
            }
        }

        maxRectangle = max(maxRectangle, largestRectangleArea(heights));
    }

    return maxRectangle;
}

int main() {
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    int result = maximalRectangle(matrix);

    cout << "Maximum rectangle area: " << result << endl;

    return 0;
}