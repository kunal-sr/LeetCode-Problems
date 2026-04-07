#include <bits/stdc++.h>
using namespace std;

class Robot {
public:
    int width, height;
    int x, y;
    int dir; // 0 = East, 1 = North, 2 = West, 3 = South
    int perimeter;

    Robot(int width, int height) {
        this->width = width;
        this->height = height;
        x = 0;
        y = 0;
        dir = 0;

        perimeter = 2 * (width + height) - 4;
    }

    void step(int num) {
        num %= perimeter;

        // Special case: if num == 0 but we completed a full cycle
        if (num == 0 && perimeter > 0) num = perimeter;

        while (num--) {
            if (dir == 0) { // East
                if (x + 1 < width) x++;
                else { dir = 1; y++; }
            }
            else if (dir == 1) { // North
                if (y + 1 < height) y++;
                else { dir = 2; x--; }
            }
            else if (dir == 2) { // West
                if (x - 1 >= 0) x--;
                else { dir = 3; y--; }
            }
            else { // South
                if (y - 1 >= 0) y--;
                else { dir = 0; x++; }
            }
        }
    }

    vector<int> getPos() {
        return {x, y};
    }

    string getDir() {
        if (dir == 0) return "East";
        if (dir == 1) return "North";
        if (dir == 2) return "West";
        return "South";
    }
};

int main() {
    Robot robot(6, 3);

    robot.step(2);
    vector<int> pos1 = robot.getPos();
    cout << "Position: (" << pos1[0] << ", " << pos1[1] << ")\n";
    cout << "Direction: " << robot.getDir() << "\n";

    robot.step(2);
    vector<int> pos2 = robot.getPos();
    cout << "Position: (" << pos2[0] << ", " << pos2[1] << ")\n";
    cout << "Direction: " << robot.getDir() << "\n";

    robot.step(10);
    vector<int> pos3 = robot.getPos();
    cout << "Position: (" << pos3[0] << ", " << pos3[1] << ")\n";
    cout << "Direction: " << robot.getDir() << "\n";

    return 0;
}
