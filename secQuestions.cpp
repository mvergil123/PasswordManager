#include "secQuestions.h"
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#include "inputManager.h"
#include <sstream>
#include <limits>


using namespace std;

void promptQuestions(const vector<string>& QUESTIONS, int& questionChoice, const string& NAME, string& answer) {
    system("clear"); // clear the screen

    cout << NAME << ", please select a security question: " << endl;
    cout << " " << endl;
    for (size_t i = 0; i < QUESTIONS.size(); i++){ // for loop that iterates through the question vector
        cout << QUESTIONS[i] << endl;
    }
    cout << " " << endl;
    cout << "Your input: "; // get the number of the question they want

    auto selection = getInputNumber("Please select a security question", 5);
    answer = getUserInput(std::string("Type in your answer: \n") +  QUESTIONS[selection-1]);
    std::cout << "Your answer was " << answer << std::endl;
}


