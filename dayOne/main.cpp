//
// Created by dave on 28/2/22.
//

#include <iostream>
#include <fstream>
#include "main.h"

void partOne(std::string puzzleInput) {

}

void partTwo(std::string puzzleInput) {

}

void readFile(std::string puzzleInput) {
    std::ifstream file ("puzzleInput.txt");
    if (file.is_open()) {
        while (file) {
            file >> puzzleInput;
        }
    }
}

int main(int argc, char const *argv[]) {
    int mode = std::stoi(argv[1]);
    std::string puzzleInput;

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


