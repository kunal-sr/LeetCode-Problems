#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 0) return "";
        
        int n = encodedText.size();
        int cols = n / rows;
        
        string result = "";
      
        for (int startCol = 0; startCol < cols; startCol++) {
            int i = 0, j = startCol;
            
            while (i < rows && j < cols) {
                result += encodedText[i * cols + j];
                i++;
                j++;
            }
        }
      
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    string encodedText = "ch   ie   pr";
    int rows = 3;
    
    cout << sol.decodeCiphertext(encodedText, rows) << endl;
    
    return 0;
}
