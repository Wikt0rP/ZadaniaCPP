#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <map>

int main() {
    std::ifstream inputFile("input2.txt");
    if (!inputFile.is_open()) {
        std::cout << "Cannot read file";
        return 1;
    }

    std::string line;

    int isDataOn = 0;
    int gameCount = 0;

    while (std::getline(inputFile, line)) {
        gameCount++;
        std::map<std::string, int> maxDiceColors {{"red", 12}, {"blue", 14}, {"green", 13}};
        std::map<std::string, int> currentDiceColors {{"red", 0}, {"blue", 0}, {"green", 0}};

        for (int i = 0; i < line.length(); i++) {
            if (line[i] == ':') {
                isDataOn = 1;
            }

            std::string number;
            if (isDataOn == 1) {
                if (isdigit(line[i])) {
                    while (isdigit(line[i])) {
                        number += line[i];
                        i++;
                    }
                }
            }

            std::string color;
            if (line[i+1] == 'r' && line[i+2] == 'e' && line[i+3] == 'd') {
                color = "red";
            } else if (line[i+1] == 'b' && line[i+2] == 'l' && line[i+3] == 'u') {
                color = "blue";
            } else if (line[i+1] == 'g' && line[i+2] == 'r' && line[i+3] == 'e') {
                color = "green";
            }

            if (!color.empty()) {
                int num = std::stoi(number);
                if (currentDiceColors[color] < num) currentDiceColors[color] = num;
            }
        }
        isDataOn = 0;
        if (maxDiceColors["red"] >= currentDiceColors["red"] && maxDiceColors["blue"] >= currentDiceColors["blue"] && maxDiceColors["green"] >= currentDiceColors["green"]) {
            std::cout << "Gra jest możliwa do zagrania\n";
        } else {
            std::cout << "Gra jest niemożliwa do zagrania\n";
        }
        std::cout << "W grze nr." << gameCount << " potrzebne jest " << currentDiceColors["red"] << " czerwoanych, " << currentDiceColors["blue"] << " niebieskich, " << currentDiceColors["green"] << " zielonych kostek\n";
        std::cout << "-------------------------------------------------------------------------\n";
    }

    inputFile.close();
    return 0;
}
