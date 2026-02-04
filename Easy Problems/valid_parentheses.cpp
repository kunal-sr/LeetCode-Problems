#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;

    for (char ch : s) {

        // If opening bracket → push
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        else {
            // If stack empty → invalid
            if (st.empty()) return false;

            char top = st.top();
            st.pop();

            // Check matching pairs
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    // If stack empty → valid
    return st.empty();
}

int main() {
    string s;
    cout << "Enter brackets string: ";
    cin >> s;

    if (isValid(s))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}