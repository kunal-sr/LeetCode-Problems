#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {

    unordered_map<string, vector<string>> mp;

    for (int i = 0; i < strs.size(); i++) {
        string s = strs[i];

        // sort the string to make the key
        sort(s.begin(), s.end());

        mp[s].push_back(strs[i]);
    }

    vector<vector<string>> result;

    // store all anagram groups
    for (auto it : mp) {
        result.push_back(it.second);
    }

    return result;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> ans = groupAnagrams(strs);

    // print result
    for (auto group : ans) {
        cout << "[ ";
        for (auto word : group) {
            cout << word << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}