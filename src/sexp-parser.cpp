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
            (current == SPACE && next == PARENTHESE_RIGHT))
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
int count = 4; // TODO : Remove this
// TODO : Pretty print the s-expression
// From https://stackoverflow.com/questions/1649027/how-do-i-print-out-a-tree-structure
void printSEXP(const string& parsedExpression) {
//    int i = 0;
//    while (i != 8) {
//        char current = parsedExpression[0];
//        char next = parsedExpression[1];
//        if (current == PARENTHESE_LEFT && next == PARENTHESE_LEFT) {
//            count--;
//            cout << indentation << parsedExpression[0] << endl;
//            parsedExpression.erase(parsedExpression[0]);
//        } else if (current == PARENTHESE_RIGHT) {
//            count++;
//            cout << indentation << parsedExpression[0] << endl;
//            parsedExpression.erase(parsedExpression[0]);
//        } else {
//            count--;
//            cout << indentation << parsedExpression.substr(0, 12) << endl;
//            parsedExpression.erase(0, 12);
//        }
//        indentation += last ? "   " : "|  ";
//        i++;
//    }
    cout << parsedExpression;
}
