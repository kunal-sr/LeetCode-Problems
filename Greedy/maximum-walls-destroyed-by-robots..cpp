#include <bits/stdc++.h>
using namespace std;

int countWalls(vector<int>& walls, int l, int r) {
    auto it1 = lower_bound(walls.begin(), walls.end(), l);
    auto it2 = upper_bound(walls.begin(), walls.end(), r);
    return it2 - it1;
}

int maxWallsDestroyed(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
    int n = robots.size();

    vector<pair<int,int>> rob;
    for (int i = 0; i < n; i++) {
        rob.push_back({robots[i], distance[i]});
    }

    sort(rob.begin(), rob.end());
    sort(walls.begin(), walls.end());

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int pos = rob[i].first;
        int dist = rob[i].second;

        int leftL = pos - dist;
        int leftR = pos;

        if (i > 0) {
            leftL = max(leftL, rob[i - 1].first);
        }

        int leftCount = countWalls(walls, leftL, leftR);

        int rightL = pos;
        int rightR = pos + dist;

        if (i < n - 1) {
            rightR = min(rightR, rob[i + 1].first);
        }

        int rightCount = countWalls(walls, rightL, rightR);

        ans += max(leftCount, rightCount);
    }

    return ans;
}

int main() {
  
    vector<int> robots = {10, 2};
    vector<int> distance = {5, 1};
    vector<int> walls = {5, 2, 7};

    int result = maxWallsDestroyed(robots, distance, walls);
    cout << "Maximum walls destroyed: " << result << endl;

    return 0;
}
