#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {

    // sort intervals by starting time
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> result;

    int start = intervals[0][0];
    int end = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++) {

        // check if current interval overlaps
        if (intervals[i][0] <= end) {
            end = max(end, intervals[i][1]);
        } else {
            result.push_back({start, end});
            start = intervals[i][0];
            end = intervals[i][1];
        }
    }

    // add the last interval
    result.push_back({start, end});

    return result;
}

int main() {
    vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};

    vector<vector<int>> merged = mergeIntervals(intervals);

    cout << "Merged intervals:" << endl;
    for (int i = 0; i < merged.size(); i++) {
        cout << "[" << merged[i][0] << ", " << merged[i][1] << "] ";
    }

    return 0;
}