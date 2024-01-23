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
        std::cout << "#DBug: Question class empty constructor called " << std::endl;
        id = 0; question = ans1 = ans2 = ans3 = ans4 = "NULL"; correctAns = 0;
    }

    void print(){
        std::cout << question << std::endl;
        std::cout << "1. " << ans1 << std::endl;
        std::cout << "2. " << ans2 << std::endl;
        std::cout << "3. " << ans3 << std::endl;
        std::cout << "4. " << ans4 << std::endl;
    }

    //print only the question, without new line
    string getQuestion() {
        return question;
    }
};


void playQuestion(Question& q){
    string user_input;
    q.print();
    std::cout << "Enter number of your answer:" << std::endl;
//    std::cin >> user_answer;
    getline(std::cin, user_input);
    if(stoi(user_input) == q.correctAns){
        std::cout << "Correct!\n" << std::endl;
    } else {
        std::cout << "Incorrect!\n" << std::endl;
    }
}


class TriviaManager {
private:
    // Creating a node
    class Node {
    public:
        Question question;
        Node* next{};
        Node* prev{};

        Node(string q, string a1, string a2, string a3, string a4, int c, unsigned int id){
            question = Question(q, a1, a2, a3, a4, c, id);
            next = prev = nullptr;
        }

        ~Node(){
            std::cout << "#DBug: the node " << question.getQuestion() << "has been deleted" << std::endl;
        }
    };

    Node* head = nullptr;
    Node* tail = nullptr;
public:
    ~TriviaManager(){
        //free list of question nodes
        if(head){
            int i = 1;
            Node *curr;
            while(head) {
                std::cout << "#DBug: deleting node num " << i << " from list" << std::endl; i++;
                curr = head;
                head = head->next;
                delete curr;
            }
        }
    }

    // Walk the user through the process of creating a new question
    void createQuestion(){
        //get all the necessary attributes of a question from the user
        string user_input;
//        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discards the input buffer
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

        //instance a new question, fill in its attributes, and link it to questions list
        Node* q_node = new Node(new_question_text, new_question_ans1, new_question_ans2,
                                new_question_ans3, new_question_ans4, new_question_correctAns, 2);

        //connect to list (between head and whatever its pointing at)
        Node* nextnode = head;
        q_node->next = nextnode;
        head = q_node;
    }

    void printQuestionsList(){
        int i = 1;
        Node *curr = head;
        while(curr) {
            std::cout << "-Question #" << i << ":" << std::endl;
            std::cout << " " << curr->question.getQuestion() << std::endl;
            curr = curr->next;
            i++;
        }
    }

    bool playAllQuestion(){
        if(!head)
            return false;

        //play through list of questions
        int i = 1;
        Node *curr = head;
        while(curr) {
            std::cout << "Question #" << i << std::endl;
            playQuestion(curr->question);
            curr = curr->next;
            i++;
        }
        return true;
    }
};


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
            if(triviaManager.playAllQuestion())
                std::cout << "You completed all questions!" << std::endl;
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

//    Question example_question("What is the capitol of France?",
//            "Paris", "London", "Europe", "Rome", 1, 1);
//
//    //play example
//    playQuestion(example_question);
//
//
//    //now make your own question
//    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discards the input buffer
//    std::cout << "Create your own trivia! Type the question first:" << std::endl;
//    getline(std::cin, user_input);
//    string new_question_text = user_input;
//    std::cout << "Now type the first of 4 answers:" << std::endl;
//    getline(std::cin, user_input);
//    string new_question_ans1 = user_input;
//    std::cout << "Now type the second of 4 answers:" << std::endl;
//    getline(std::cin, user_input);
//    string new_question_ans2 = user_input;
//    std::cout << "Now type the third of 4 answers:" << std::endl;
//    getline(std::cin, user_input);
//    string new_question_ans3 = user_input;
//    std::cout << "Now type the last of 4 answers:" << std::endl;
//    getline(std::cin, user_input);
//    string new_question_ans4 = user_input;
//    std::cout << "Type the number of the correct answer:" << std::endl;
//    getline(std::cin, user_input);
//    int new_question_correctAns = stoi(user_input);
//
//    Question user_question(new_question_text, new_question_ans1, new_question_ans2,
//                            new_question_ans3, new_question_ans4, new_question_correctAns, 2);
//
//    std::cout << "\nGreat lets try out your trivia question!" << std::endl;
//    playQuestion(user_question);

    // TODO (IMPORTANT) line 123 calls empty constructor of Question, we dont want that!
    // TODO give user score once they complete all questions
    // TODO make the list a double list
    // TODO implement save file.(docker server, mysql)

    ///(Unrelated)cool idea: make a checkInput() operator in a different .header and
    /// and make it take args like "check single digit", "check single word" etc.

    return 0;
}