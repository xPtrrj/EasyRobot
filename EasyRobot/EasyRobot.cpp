#include <iostream>
#include <string>
#include <algorithm>

class Robot {
private:
    int x;
    int y;
    std::string direction;

public:
    Robot() {
        x = -1;
        y = -1;
        direction = "";
    }

    void place(int xPos, int yPos, std::string dir) {
        if (xPos < 0 || xPos > 4 || yPos < 0 || yPos > 4) {
            std::cout << "Invalid position. Please enter values between 0 and 4." << std::endl;
            return;
        }

        if (dir != "north" && dir != "east" && dir != "south" && dir != "west") {
            std::cout << "Invalid direction. Please enter one of: north, east, south, west." << std::endl;
            return;
        }

        x = xPos;
        y = yPos;
        direction = dir;

        std::cout << "Robot placed at (" << x << "," << y << ") facing " << direction << "." << std::endl;
    }

    void move() {
        if (direction == "") {
            std::cout << "Robot has not been placed yet. Please place the robot first." << std::endl;
            return;
        }

        if (direction == "north") {
            if (y < 4) {
                y++;
            }
            else {
                std::cout << "Sorry, I cannot move further in that direction." << std::endl;
            }
        }
        else if (direction == "east") {
            if (x < 4) {
                x++;
            }
            else {
                std::cout << "Sorry, I cannot move further in that direction." << std::endl;
            }
        }
        else if (direction == "south") {
            if (y > 0) {
                y--;
            }
            else {
                std::cout << "Sorry, I cannot move further in that direction." << std::endl;
            }
        }
        else if (direction == "west") {
            if (x > 0) {
                x--;
            }
            else {
                std::cout << "Sorry, I cannot move further in that direction." << std::endl;
            }
        }
    }

    void turnLeft() {
        if (direction == "") {
            std::cout << "Robot has not been placed yet. Please place the robot first." << std::endl;
            return;
        }

        if (direction == "north") {
            direction = "west";
        }
        else if (direction == "east") {
            direction = "north";
        }
        else if (direction == "south") {
            direction = "east";
        }
        else if (direction == "west") {
            direction = "south";
        }

        std::cout << "Robot turned left. Now facing " << direction << "." << std::endl;
    }

    void turnRight() {
        if (direction == "") {
            std::cout << "Robot has not been placed yet. Please place the robot first." << std::endl;
            return;
        }

        if (direction == "north") {
            direction = "east";
        }
        else if (direction == "east") {
            direction = "south";
        }
        else if (direction == "south") {
            direction = "west";
        }
        else if (direction == "west") {
            direction = "north";
        }

        std::cout << "Robot turned right. Now facing " << direction << "." << std::endl;
    }

    void report() {
        std::cout << "Output: " << x << "," << y << "," << direction << std::endl;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    std::string getDirection() {
        return direction;
    }
};

int main() {
    Robot robot;

    std::cout << "Welcome to the Robot Simulator!" << std::endl;

    while (true) {
        std::cout << "Please enter a command (PLACE X,Y,DIRECTION, MOVE, LEFT, RIGHT, REPORT, or EXIT): ";
        std::string input;
        std::getline(std::cin, input);

        // Convert input to lowercase
        std::transform(input.begin(), input.end(), input.begin(), [](unsigned char c) { return std::tolower(c); });

        if (input.substr(0, 5) == "place") {
            int xPos = std::stoi(input.substr(6, 1));
            int yPos = std::stoi(input.substr(8, 1));
            std::string direction = input.substr(10);

            robot.place(xPos, yPos, direction);
        }
        else if (input == "move") {
            robot.move();
        }
        else if (input == "left") {
            robot.turnLeft();
        }
        else if (input == "right") {
            robot.turnRight();
        }
        else if (input == "report") {
            robot.report();

            // Visualization
            std::cout << std::endl;
            for (int i = 4; i >= 0; i--) {
                std::cout << i;
                for (int j = 0; j < 5; j++) {
                    if (robot.getX() == j && robot.getY() == i) {
                        std::cout << " " << robot.getDirection()[0];
                    }
                    else {
                        std::cout << "  ";
                    }
                }
                std::cout << std::endl;
            }
            std::cout << "  0  1  2  3  4" << std::endl;
        }
        else if (input == "exit") {
            break;
        }
        else {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }

    std::cout << "Thank you for using the Robot Simulator!" << std::endl;

    return 0;
}