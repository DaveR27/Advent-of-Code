//
// Created by David on 28/02/2022.
//

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <tuple>

void partOne(const std::list<std::pair<std::string, int>>& puzzleInput) {
    std::pair<int, int> position (0,0);
    std::string up = "up";
    std::string down = "down";
    std::string forward = "forward";

    for (const std::pair<std::string, int>& coOrds : puzzleInput) {

        if (coOrds.first == up) {
            position.second = position.second - coOrds.second;
        }
        if (coOrds.first == down) {
            position.second = position.second + coOrds.second;
        }
        if (coOrds.first == forward) {
            position.first = position.first + coOrds.second;
        }
    }

    int multiplied = position.first * position.second;
    std::cout << "The positions multiplied are: " << multiplied << std::endl;
}

void partTwo(const std::list<std::pair<std::string, int>>& puzzleInput) {
    std::tuple<int, int, int> positions(0, 0, 0);
    std::string up = "up";
    std::string down = "down";
    std::string forward = "forward";

    for (const std::pair<std::string, int>& coOrds : puzzleInput) {
        if (coOrds.first == up) {
            std::get<2>(positions) = std::get<2>(positions) - coOrds.second;
        }
        if (coOrds.first == down) {
            std::get<2>(positions) = std::get<2>(positions) + coOrds.second;
        }
        if (coOrds.first == forward) {
            std::get<0>(positions) = std::get<0>(positions) + coOrds.second;
            std::get<1>(positions) = std::get<1>(positions) + (coOrds.second * std::get<2>(positions));
        }
    }

    int multiplied = std::get<0>(positions) * std::get<1>(positions);
    std::cout << "The positions multiplied are: " << multiplied << std::endl;
}

std::string removeEscape(const std::string& commandString) {
    std::stringstream stringStream (commandString);
    std::string line;

    getline(stringStream, line, '\r');
    return line;
}

std::vector<std::string> splitLines(const std::string& commandString) {
    std::stringstream stringStream (commandString);
    std::string line;
    std::vector<std::string> commands;

    while (getline(stringStream, line, ' ')) {
        commands.push_back(removeEscape(line));
    }

    return commands;
}

std::list<std::pair<std::string, int>> readFile() {
    std::ifstream file("puzzleInput.txt");
    std::list<std::pair<std::string, int>> puzzleInput;
    std::string line;
    int count = 0;
    if (file.is_open()) {
        while (getline(file, line)) {
            count++;
            std::vector<std::string> commands = splitLines(line);
            std::string key = commands.at(0);
            int value = std::stoi(commands.at(1));
            std::pair<std::string, int> pair (key, value);
            puzzleInput.push_back(pair);
        }
    }
    return puzzleInput;
}

int main(int argc, char const *argv[]) {
    int mode = std::stoi(argv[1]);
    std::list<std::pair<std::string, int>> puzzleInput = readFile();

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