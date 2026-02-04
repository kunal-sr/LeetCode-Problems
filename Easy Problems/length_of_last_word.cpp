#include <bits/stdc++.h>
using namespace std;

int lengthOfLastWord(string s) {
    int count = 0;
    int i = s.length() - 1;

    // skip trailing spaces
    while (i >= 0 && s[i] == ' ') {
        i--;
    }

    // count characters of last word
    while (i >= 0 && s[i] != ' ') {
        count++;
        i--;
    }

    return count;
}

int main() {
    string s = "   fly me   to   the moon  ";

    int result = lengthOfLastWord(s);
    cout << "Length of last word: " << result << endl;

    return 0;
}