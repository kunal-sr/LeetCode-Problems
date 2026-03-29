#include <bits/stdc++.h>
using namespace std;

bool checkOnesSegment(string s) {
    int count = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1' && (i == 0 || s[i - 1] == '0')) {
            count++;
        }
    }

    return count <= 1;
}

int main() {
    string s = "110";
    
    if (checkOnesSegment(s))
        cout << "True\n";
    else
        cout << "False\n";

    return 0;
}
