#include <utility>

//
// Created by Hani on 26/01/2024.
//

#include <iostream>
#include <string>
using std::string;


class Question {
private:
    unsigned int id;        // Unused attribute
    string question;
    string ans1;
    string ans2;
    string ans3;
    string ans4;
public:
    int correctAns;
    Question(string &q, string &a1, string &a2, string &a3, string &a4, int c, unsigned int id=1):
        id(id), question(q), ans1(a1), ans2(a2), ans3(a3), ans4(a4), correctAns(c) {}

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

// *Consider turning this into member function of class Question.
bool playQuestion(Question& q){
    string user_input;
    q.print();
    std::cout << "Enter number of your answer:" << std::endl;
//    std::cin >> user_answer;
    getline(std::cin, user_input);
    if(stoi(user_input) == q.correctAns){
        std::cout << "Correct!\n" << std::endl;
        return true;
    } else {
        std::cout << "Incorrect!\n" << std::endl;
        return false;
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

        Node(string q, string a1, string a2, string a3, string a4, int c, unsigned int id):
                question(q, a1, a2, a3, a4, c, id) {}

        ~Node(){
            std::cout << "#DBug: the node " << question.getQuestion() << "has been deleted" << std::endl;
        }
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;
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

        if(nextnode)
            nextnode->prev = q_node;
        else
            tail = q_node; //edgecase that we insert a node for the first time

        size++;
    }

    void printQuestionsList(){
        int i = 1;
        Node *curr = tail;
        while(curr) {
            std::cout << "-Question #" << i << ":" << std::endl;
            std::cout << " " << curr->question.getQuestion() << std::endl;
            curr = curr->prev;
            i++;
        }
    }

    //Play through all question starting from tail. Returns number of questions
    //that were correctly answered, if there are no questions, returns -1.
    int playAllQuestion(){
        if(!tail)
            return -1;

        //play through list of questions
        int i = 1;
        int score = 0;
        Node *curr = tail;
        while(curr) {
            std::cout << "Question #" << i << std::endl;
            score += playQuestion(curr->question);
            curr = curr->prev;
            i++;
        }
        return score;
    }

    int getSize() { return size; }
};


