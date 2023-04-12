#include <iostream>
#include <string>

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