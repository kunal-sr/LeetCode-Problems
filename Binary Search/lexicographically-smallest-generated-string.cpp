#include <bits/stdc++.h>
using namespace std;

string robotWithString(string s) {
    vector<int> freq(26, 0);
  
    for (char c : s) {
        freq[c - 'a']++;
    }

    stack<char> st;
    string result = "";

    for (char c : s) {
        st.push(c);
        freq[c - 'a']--;

        char smallest = 'a';
        while (smallest <= 'z' && freq[smallest - 'a'] == 0) {
            smallest++;
        }

        while (!st.empty() && st.top() <= smallest) {
            result += st.top();
            st.pop();
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    cout << "Lexicographically smallest string: " 
         << robotWithString(s) << endl;

    return 0;
}
