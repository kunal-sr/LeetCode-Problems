#include <bits/stdc++.h>
using namespace std;

string result = "";
int countStr = 0;

void backtrack(int n, int k, string &curr) {
    if (curr.size() == n) {
        countStr++;
        if (countStr == k) {
            result = curr;
        }
        return;
    }

    for (char ch : {'a', 'b', 'c'}) {
        if (!curr.empty() && curr.back() == ch) continue;

        curr.push_back(ch);
        backtrack(n, k, curr);
        curr.pop_back();

        if (!result.empty()) return;
    }
}

string getHappyString(int n, int k) {
    string curr = "";
    backtrack(n, k, curr);
    return result;
}

int main() {
    int n = 3, k = 9;
    cout << getHappyString(n, k) << endl;
    return 0;
}
