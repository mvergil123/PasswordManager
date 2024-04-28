
#include <vector>
#include <string>
#include <iostream>

int getInputNumber(std::string output, int numberOfChoices) {
    auto isSelectionBad = false;
    do {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max());
        std::cout << output << std::endl;
        auto userSelection = -1;
        std::cin >> userSelection;
        isSelectionBad = userSelection < 0 || userSelection >= numberOfChoices;
        if (!isSelectionBad) {
            return userSelection;
        }
    } while (isSelectionBad);
    return -1;
}

