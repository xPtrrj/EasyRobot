#include <iostream>
#include <string>
#include <algorithm>
#include "Robot.h"

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