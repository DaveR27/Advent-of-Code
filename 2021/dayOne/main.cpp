//
// Created by dave on 28/2/22.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <numeric>

void partOne(const std::vector<int> &puzzleInput) {
    int count = 0;
    int previousMeasurement = -1;

    for (int currentNumber: puzzleInput) {
        if (previousMeasurement != -1 && previousMeasurement < currentNumber) {
            count++;
        }
        previousMeasurement = currentNumber;
    }

    std::cout << "The total is: " << count << std::endl;
}

void partTwo(const std::vector<int> &puzzleInput) {
    int count = 0;
    int previousMeasurement = -1;
    std::deque<int> frame;

    for (int number: puzzleInput) {
        frame.push_back(number);

        if (frame.size() == 3) {
            int sum = std::accumulate(frame.begin(), frame.end(), 0);

            if (previousMeasurement != -1 && previousMeasurement < sum) {
                count++;
            }
            frame.pop_front();
            previousMeasurement = sum;
        }
    }

    std::cout << "The total is: " << count << std::endl;
}

std::vector<int> readFile() {
    std::ifstream file("puzzleInput.txt");
    std::vector<int> puzzleInput;
    std::string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            puzzleInput.push_back(std::stoi(line));
        }
    }
    return puzzleInput;
}

int main(int argc, char const *argv[]) {
    int mode = std::stoi(argv[1]);
    std::vector<int> puzzleInput = readFile();

    switch (mode) {
        case 1:
            partOne(puzzleInput);
            break;
        case 2:
            partTwo(puzzleInput);
            break;
        default:
            std::cout << "Please choose 1 or 2" << std::endl;
    }
}


