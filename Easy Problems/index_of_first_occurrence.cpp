#include <iostream>
using namespace std;

int strStr(string haystack, string needle) {

    int n = haystack.length();
    int m = needle.length();

    // If needle is longer, impossible to match
    if (m > n) return -1;

    for (int i = 0; i <= n - m; i++) {

        int j = 0;

        // Compare characters
        while (j < m && haystack[i + j] == needle[j]) {
            j++;
        }

        // If entire needle matched
        if (j == m) {
            return i;
        }
    }

    return -1;
}

int main() {
    string haystack, needle;

    cout << "Enter haystack: ";
    cin >> haystack;

    cout << "Enter needle: ";
    cin >> needle;

    int result = strStr(haystack, needle);

    cout << "Output: " << result << endl;

    return 0;
}