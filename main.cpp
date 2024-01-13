/// Trivia maker - via Hani(pbuh) 12.1.2024

#include <iostream>
#include <string>
using std::string;


class Question {       // The class
private:             // Access specifier
    unsigned int id;        // Attribute (int variable)
    string question;  // Attribute (string variable)
    string ans1;
    string ans2;
    string ans3;
    string ans4;
public:
    int correctAns;
    Question(string q, string a1, string a2, string a3, string a4, int c, unsigned int id=0){ // Constructor with parameters
        id = id;
        question = q;
        ans1 = a1;
        ans2 = a2;
        ans3 = a3;
        ans4 = a4;
        correctAns = c;
    }

    Question(){
        id = 0; question = ans1 = ans2 = ans3 = ans4 = "NULL"; correctAns = 0;
    }

    void print(){
        std::cout << question << std::endl;
        std::cout << "1. " << ans1 << std::endl;
        std::cout << "2. " << ans2 << std::endl;
        std::cout << "3. " << ans3 << std::endl;
        std::cout << "4. " << ans4 << std::endl;
    }
};

class TriviaManager {
private:
    // Creating a node
    class Node {
    public:
        Question question;
        Node* next;
        Node* prev;
    };
    Node* head = nullptr;
    Node* tail = nullptr;
public:
    // Walk the user through the process of creating a new question
    void createQuestion(){
        string user_input;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discards the input buffer
        std::cout << "Create your own trivia! Type the question first:" << std::endl;
        getline(std::cin, user_input);
        string new_question_text = user_input;
        std::cout << "Now type the first of 4 answers:" << std::endl;
        getline(std::cin, user_input);
        string new_question_ans1 = user_input;
        std::cout << "Now type the second of 4 answers:" << std::endl;
        getline(std::cin, user_input);
        string new_question_ans2 = user_input;
        std::cout << "Now type the third of 4 answers:" << std::endl;
        getline(std::cin, user_input);
        string new_question_ans3 = user_input;
        std::cout << "Now type the last of 4 answers:" << std::endl;
        getline(std::cin, user_input);
        string new_question_ans4 = user_input;
        std::cout << "Type the number of the correct answer:" << std::endl;
        getline(std::cin, user_input);
        int new_question_correctAns = stoi(user_input);

        Node* q_node = new Node(); //check for failure!!!
        q_node->prev = q_node->next->next;
        q_node->next = head;
        Question user_question(new_question_text, new_question_ans1, new_question_ans2,
                               new_question_ans3, new_question_ans4, new_question_correctAns, 2);
    }
};


void playQuestion(Question& q){
    int user_answer;
    q.print();
    std::cout << "Enter number of your answer:" << std::endl;
    std::cin >> user_answer;
    if(user_answer == q.correctAns){
        std::cout << "Correct!\n" << std::endl;
    } else {
        std::cout << "Incorrect!\n" << std::endl;
    }
}


int main() {
    string user_input;

    std::cout << "  Welcome to Trivia Maker" << std::endl;
    std::cout << "Would you like to play or make trivia? (press 'p' to play,"
                 " or 'm' to make trivia)" << std::endl;
    getline(std::cin, user_input);
    if(user_input == "p"){
        //play
    } else if(user_input == "m") {
        //make
    } else {
        std::cout << "~Quit" << std::endl;
        return 0;
    }

    Question example_question("What is the capitol of France?",
            "Paris", "London", "Europe", "Rome", 1, 1);

    //play example
    playQuestion(example_question);


    //now make your own question
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discards the input buffer
    std::cout << "Create your own trivia! Type the question first:" << std::endl;
    getline(std::cin, user_input);
    string new_question_text = user_input;
    std::cout << "Now type the first of 4 answers:" << std::endl;
    getline(std::cin, user_input);
    string new_question_ans1 = user_input;
    std::cout << "Now type the second of 4 answers:" << std::endl;
    getline(std::cin, user_input);
    string new_question_ans2 = user_input;
    std::cout << "Now type the third of 4 answers:" << std::endl;
    getline(std::cin, user_input);
    string new_question_ans3 = user_input;
    std::cout << "Now type the last of 4 answers:" << std::endl;
    getline(std::cin, user_input);
    string new_question_ans4 = user_input;
    std::cout << "Type the number of the correct answer:" << std::endl;
    getline(std::cin, user_input);
    int new_question_correctAns = stoi(user_input);

    Question user_question(new_question_text, new_question_ans1, new_question_ans2,
                            new_question_ans3, new_question_ans4, new_question_correctAns, 2);

    std::cout << "\nGreat lets try out your trivia question!" << std::endl;
    playQuestion(user_question);

    ///make it possible to generate as many q's as the user wants (dynamic mem)
    ///and give user ability to choose between 'play mode' and 'create mode'.
    ///lastly implement save file.

    return 0;
}