#include <bits/stdc++.h>
using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result;
    int n = words.size();
    int i = 0;

    while (i < n) {
        int lineLen = words[i].length();
        int j = i + 1;

        // pack as many words as possible
        while (j < n && lineLen + 1 + words[j].length() <= maxWidth) {
            lineLen += 1 + words[j].length();
            j++;
        }

        int wordCount = j - i;
        string line = "";

        // last line or only one word -> left justify
        if (j == n || wordCount == 1) {
            for (int k = i; k < j; k++) {
                line += words[k];
                if (k != j - 1) {
                    line += " ";
                }
            }

            // fill remaining spaces
            while (line.length() < maxWidth) {
                line += " ";
            }
        } 
        else {
            // fully justify
            int totalWordLen = 0;
            for (int k = i; k < j; k++) {
                totalWordLen += words[k].length();
            }

            int totalSpaces = maxWidth - totalWordLen;
            int spaceBetween = totalSpaces / (wordCount - 1);
            int extraSpaces = totalSpaces % (wordCount - 1);

            for (int k = i; k < j; k++) {
                line += words[k];

                if (k != j - 1) {
                    for (int s = 0; s < spaceBetween; s++) {
                        line += " ";
                    }
                    if (extraSpaces > 0) {
                        line += " ";
                        extraSpaces--;
                    }
                }
            }
        }

        result.push_back(line);
        i = j;
    }

    return result;
}

int main() {
    vector<string> words = {
        "This", "is", "an", "example", "of", "text", "justification."
    };
    int maxWidth = 16;

    vector<string> result = fullJustify(words, maxWidth);

    cout << "Justified Text:\n";
    for (string line : result) {
        cout << "\"" << line << "\"" << endl;
    }

    return 0;
}