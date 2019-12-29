/***********************************************************************************
 * @brief The source file containing the implementation of functions of the s-expression parser
 * @author Nathanaël Beaudoin-Dion
 * @date December 27th 2019
 ***********************************************************************************/

/// STANDARD INCLUDES
#include <string>
#include <iostream>
#include <fstream>
#include <cassert>

/// SEXP-PARSER INCLUDES
#include "sexp-parser.hpp"

/// NAMESPACE
using namespace std;

/// IMPLEMENTATION OF FUNCTIONS

string readFileSEXP(const string& fileName) {
    ifstream file;
    string fileTextTemp;
    string lineTemp;
    file.open(fileName);
    if (file.is_open()) {
        while (getline(file, lineTemp)) {
            fileTextTemp += lineTemp;
        }
        file.close();
    } else {
        cout << ERR_FILE_MESSAGE;
        assert(file.is_open());
    }
    return fileTextTemp;
}

// TODO : Add "" implementation
// TODO : Make binary expressions
string parseSEXP(const string& sexpExpression) {
    string parsedExpression;
    for (unsigned int i = 0; i < sexpExpression.length() - 1; i++) {
        char current = sexpExpression[i];
        char next = sexpExpression[i + 1];
        // current is an unnecessary character which is not added to the parsedExpression
        if ((current == SPACE && next == SPACE) || (current == SPACE && next == PARENTHESE_LEFT) ||
            (current == SPACE && next == PARENTHESE_RIGHT) || (current == TAB))
            continue;
        // next is a printable and correct character between a comma and the letter z
        else if (current == PARENTHESE_LEFT && START_CORRECT_CHAR <= next && next <= END_CORRECT_CHAR)
            parsedExpression += PARENTHESE_LEFT + DATA_TYPE_ELEMENT;
        else if (current == SPACE && START_CORRECT_CHAR <= next && next <= END_CORRECT_CHAR)
            parsedExpression += SPACE + VALUE_ELEMENT;
        // current is a necessary character for the s-expression
        else
            parsedExpression += current;
    }
    return parsedExpression;
}

// TODO : Pretty print the s-expression
void printSEXP(const string& parsedExpression) {
    cout << parsedExpression;
}
