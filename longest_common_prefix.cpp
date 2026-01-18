#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    // if array is empty
    if (strs.size() == 0)
        return "";

    // take first string as prefix
    string prefix = strs[0];

    // compare prefix with each string
    for (int i = 1; i < strs.size(); i++) {
        int j = 0;

        // compare characters one by one
        while (j < prefix.length() && j < strs[i].length() &&
               prefix[j] == strs[i][j]) {
            j++;
        }

        // shorten prefix
        prefix = prefix.substr(0, j);

        // if prefix becomes empty
        if (prefix == "")
            return "";
    }

    return prefix;
}

int main() {
    vector<string> strs = {"flower", "flow", "flight"};

    string result = longestCommonPrefix(strs);

    cout << "Longest Common Prefix: " << result << endl;

    return 0;
}