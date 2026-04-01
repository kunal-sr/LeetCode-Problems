#include <bits/stdc++.h>
using namespace std;

vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
    int n = positions.size();

    // Step 1: sort indices by position
    vector<int> idx(n);
    for (int i = 0; i < n; i++) idx[i] = i;

    sort(idx.begin(), idx.end(), [&](int a, int b) {
        return positions[a] < positions[b];
    });

    stack<int> st; // stores indices of robots moving right

    for (int i : idx) {
        if (directions[i] == 'R') {
            st.push(i);
        } else {
            // robot moving left
            while (!st.empty() && healths[i] > 0) {
                int j = st.top();

                if (healths[j] < healths[i]) {
                    st.pop();
                    healths[i]--;
                } 
                else if (healths[j] > healths[i]) {
                    healths[j]--;
                    healths[i] = 0;
                } 
                else {
                    st.pop();
                    healths[i] = 0;
                    healths[j] = 0;
                }
            }
        }
    }

    // collect survivors
    vector<pair<int,int>> survivors;
    for (int i = 0; i < n; i++) {
        if (healths[i] > 0) {
            survivors.push_back({i, healths[i]});
        }
    }

    sort(survivors.begin(), survivors.end());

    vector<int> result;
    for (auto &p : survivors) {
        result.push_back(p.second);
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> positions(n), healths(n);
    for (int i = 0; i < n; i++) cin >> positions[i];
    for (int i = 0; i < n; i++) cin >> healths[i];

    string directions;
    cin >> directions;

    vector<int> result = survivedRobotsHealths(positions, healths, directions);

    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}