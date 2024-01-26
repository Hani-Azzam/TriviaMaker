/// Trivia maker - via Hani(pbuh) 12.1.2024

#include <iostream>
#include <string>
#include "TriviaManager.cpp"
using std::string;


int main() {
    string user_input;
    TriviaManager triviaManager;

    std::cout << "+  Welcome to Trivia Maker  +" << std::endl;
    while(true) {
        std::cout << "Would you like to play or make trivia? (press 'p' to play,"
                   " or 'm' to make trivia)" << std::endl;
        getline(std::cin, user_input);
        if (user_input == "p") {
            //play through list of questions
            int score = triviaManager.playAllQuestion();
            if(score >= 0)
                std::cout << "You completed all questions! you answered "
                              << score << " questions correctly out of " <<
                              triviaManager.getSize() << std::endl;
            else
                std::cout << "No questions found" << std::endl;
        } else if (user_input == "m") {
            //make
            triviaManager.createQuestion();
        } else if(user_input == "d"){
            //debug
            std::cout << "~Debug mode printing all questions:" << std::endl;
            triviaManager.printQuestionsList();
        } else {
            std::cout << "~Quit" << std::endl;
            break;
        }
    }

    // TODO implement save file.(docker server, mysql)

    ///(Unrelated)cool idea: make a checkInput() operator in a different .header and
    /// and make it take args like "check single digit", "check single word" etc.

    return 0;
}