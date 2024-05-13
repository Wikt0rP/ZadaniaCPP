#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int wordToNum(std::string word){
    if(word == "one") return 1;
    if(word == "two") return 2;
    if(word == "three") return 3;
    if(word == "four") return 4;
    if(word == "five") return 5;
    if(word == "six") return 6;
    if(word == "seven") return 7;
    if(word == "eight") return 8;
    if(word == "nine") return 9;
    return -1;
}

void replaceWordsWithNumbers(std::string& str){
    std::string words[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for(int i = 0; i < 9; i++){
        size_t pos = str.find(words[i]);
        while(pos != std::string::npos){
            str.replace(pos, words[i].length(), std::to_string(i + 1));
            pos = str.find(words[i]);
        }
    }
}

void printFirstAndLastDigit(std::string str, int& sum){
    bool firstDigitFound = false;
    char firstDigit, lastDigit;
    for(char& c : str){
        if(isdigit(c)){
            if(!firstDigitFound){
                firstDigit = c;
                firstDigitFound = true;
            }
            lastDigit = c;
        }
    }
    if(firstDigitFound){
        std::cout << firstDigit << lastDigit << "\n";
        std::string twoDigitStr = {firstDigit, lastDigit};
        sum += std::stoi(twoDigitStr);
    }
}

int main() {
    std::ifstream fptr("input.txt");
    if(!fptr.is_open()){
        std::cout << "Nie mozna odczytac pliku";
        return 1;
    }

    std::string str;
    int sum = 0;
    while(std::getline(fptr, str)){
        replaceWordsWithNumbers(str);
        printFirstAndLastDigit(str, sum);
        std::cout << str << "\n";
    }

    std::cout << "Suma: " << sum << "\n";

    fptr.close();
    return 0;
}
