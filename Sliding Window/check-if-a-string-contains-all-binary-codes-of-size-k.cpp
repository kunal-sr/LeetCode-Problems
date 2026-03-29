#include <bits/stdc++.h>
using namespace std;

bool hasAllCodes(string s, int k) {
    int n = s.size();
    if (n < k) return false;

    int total = 1 << k;
    vector<bool> seen(total, false);

    int hash = 0;
    int mask = total - 1;

    for (int i = 0; i < n; i++) {

        hash = ((hash << 1) & mask) | (s[i] - '0');

        if (i >= k - 1) {
            if (!seen[hash]) {
                seen[hash] = true;
                total--;
                if (total == 0) return true;
            }
        }
    }

    return false;
}

int main() {
    string s = "00110110";
    int k = 2;

    if (hasAllCodes(s, k)) {
        cout << "Yes, all binary codes of size k exist.\n";
    } else {
        cout << "No, some binary codes are missing.\n";
    }

    return 0;
}
