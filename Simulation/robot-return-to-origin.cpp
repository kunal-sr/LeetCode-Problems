#include <iostream>
#include <string>
using namespace std;

bool judgeCircle(string moves) {
    int x = 0, y = 0;

    for (char move : moves) {
        if (move == 'U') y++;
        else if (move == 'D') y--;
        else if (move == 'R') x++;
        else if (move == 'L') x--;
    }

    return (x == 0 && y == 0);
}

int main() {
    string moves;
    cout << "Enter moves: ";
    cin >> moves;

    if (judgeCircle(moves)) {
        cout << "True (Robot returned to origin)" << endl;
    } else {
        cout << "False (Robot did not return to origin)" << endl;
    }

    return 0;
}
