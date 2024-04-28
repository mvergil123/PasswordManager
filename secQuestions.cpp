#include "secQuestions.h"
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#include "inputManager.h"
#include <sstream>


using namespace std;




void promptQuestions(const vector<string>& QUESTIONS, int& questionChoice, const string& NAME, string& answer){
    system("clear"); // clear the screen
    std::stringstream ss;


    ss << NAME << ", please select a security question: " << endl;
    ss << " " << endl;
    for (size_t i = 0; i < QUESTIONS.size(); i++){ // for loop that iterates through the question vector
        ss << QUESTIONS[i] << endl;
    }

    ss << " " << endl;
    ss << "Your input: "; // get the number of the question they want

    cout << ss.str();

    cin >> questionChoice;

    auto selection = getInputNumber(ss.str());
    cout << selection << endl;

    /*while (questionChoice <= 0 || questionChoice > int(QUESTIONS.size()))
    { // while loop that makes sure the user answered properly
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid option. Please type in a valid number: ";
        cin >> questionChoice;
        cout << " " << endl;
    }
    cout << " " << endl;*/

    cout << "Type in your answer:" << endl;
    cout << QUESTIONS[questionChoice - 1] << ": ";


    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, answer); // get the answer to the question 

    cout << " " << endl;
}


