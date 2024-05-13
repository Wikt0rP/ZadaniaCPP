#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Game {
    int id;
    vector<int> reds, greens, blues;
};

int main() {
    ifstream file("/Users/wiktor/Library/Mobile Documents/com~apple~CloudDocs/c/untitled2/input.txt");
    if (!file) {
        cerr << "Nie można otworzyć pliku input.txt" << endl;
        return 1; // zwraca kod błędu 1
    }

    string line;
    vector<Game> games;
    int gameId = 0;
    while (getline(file, line)) {
        if (line.find("Game") != string::npos) {
            games.push_back(Game());
            gameId++;
            games.back().id = gameId;
            continue;
        }
        istringstream iss(line);
        int red = 0, green = 0, blue = 0;
        string color;
        int count;
        while (iss >> count >> color) {
            if (color == "red") red = count;
            else if (color == "green") green = count;
            else if (color == "blue") blue = count;
        }
        games.back().reds.push_back(red);
        games.back().greens.push_back(green);
        games.back().blues.push_back(blue);
    }

    int sum1 = 0, sum2 = 0;
    for (const auto& game : games) {
        int maxRed = game.reds.empty() ? 0 : *max_element(game.reds.begin(), game.reds.end());
        int maxGreen = game.greens.empty() ? 0 : *max_element(game.greens.begin(), game.greens.end());
        int maxBlue = game.blues.empty() ? 0 : *max_element(game.blues.begin(), game.blues.end());

        if (maxRed <= 12 && maxGreen <= 13 && maxBlue <= 14) {
            sum1 += game.id;
        }

        sum2 += maxRed * maxGreen * maxBlue;
    }

    cout << "Suma identyfikatorów gier: " << sum1 << endl;
    cout << "Suma mocy zestawów: " << sum2 << endl;

    return 0;
}
