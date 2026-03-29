#include <bits/stdc++.h>
using namespace std;

string findTheString(vector<vector<int>>& lcp) {
    int n = lcp.size();
    string s(n, '#');

    char ch = 'a';

    for (int i = 0; i < n; i++) {
        if (s[i] == '#') {
            if (ch > 'z') return "";

            for (int j = i; j < n; j++) {
                if (lcp[i][j] > 0) {
                    s[j] = ch;
                }
            }
            ch++;
        }
    }

    vector<vector<int>> check(n, vector<int>(n, 0));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (s[i] == s[j]) {
                if (i == n - 1 || j == n - 1)
                    check[i][j] = 1;
                else
                    check[i][j] = 1 + check[i + 1][j + 1];
            } else {
                check[i][j] = 0;
            }
        }
    }

    if (check == lcp) return s;
    return "";
}

int main() {
    vector<vector<int>> lcp = {
        {3,0,1},
        {0,2,0},
        {1,0,1}
    };

    cout << findTheString(lcp) << endl;
    return 0;
}
