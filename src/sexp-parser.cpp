/***********************************************************************************
 * @brief The source file containing the implementation of functions of the s-expression parser
 * @author Nathanaël Beaudoin-Dion
 * @date December 27th 2019
 ***********************************************************************************/

/// STANDARD INCLUDES
#include <string>
#include <iostream>
#include <fstream>
#include <dirent.h>

/// SEXP-PARSER INCLUDES
#include "sexp-parser.hpp"

/// NAMESPACE
using namespace std;

/// IMPLEMENTATION OF FUNCTIONS

string findFileSEXP(const char* directoryName) {
    string fileName;
    DIR* directory = opendir(directoryName);
    struct dirent* ent;
    if (directory != nullptr) { // Search in the directory for
        cout << "Choose the .sexp file you want to parse by typing the name with the file extension: " << endl;
        while ((ent = readdir(directory)) != nullptr) {
            string file = static_cast<string>(ent->d_name);
            if (file == "." || file == ".." ) // Don't print unnecessary file names
                continue;
            cout << "\t - " << file << endl;
        }
        cin >> fileName;
        closedir(directory);
    } else { // Could not open the directory
        perror("");
    }
    return fileName;
}

string readFileSEXP(const string& fileName) {
    ifstream file;
    string fileTextTemp;
    string lineTemp;
    file.open(S_EXPRESSIONS_DIRECTORY + fileName);
    if (file.is_open()) {
        while (getline(file, lineTemp)) {
            fileTextTemp += lineTemp;
        }
        file.close();
    } else { // Could not open the file
        string newFileName;
        cout << "A problem happened with the selected file, re-enter the name: " << endl;
        cin >> newFileName;
        fileTextTemp = readFileSEXP(newFileName); // Retry
    }
    return fileTextTemp;
}

// TODO : Add "" implementation
string simplifySEXP(const string& sexpExpression) {
    string simplifiedExpression;
    for (unsigned int i = 0; i < sexpExpression.length() - 1; i++) {
        char current = sexpExpression[i];
        char next = sexpExpression[i + 1];
        // next is a printable and correct character between a comma and the letter z
        if (current == PARENTHESE_LEFT && START_CORRECT_CHAR <= next && next <= END_CORRECT_CHAR)
            simplifiedExpression += PARENTHESE_LEFT + DATA_TYPE_ELEMENT;
        else if (current == SPACE && START_CORRECT_CHAR <= next && next <= END_CORRECT_CHAR)
            simplifiedExpression += SPACE + VALUE_ELEMENT;
        // current is a printable and correct character
        else if ((START_CORRECT_CHAR <= current && current <= END_CORRECT_CHAR) ||
                 current == PARENTHESE_LEFT || current == PARENTHESE_RIGHT)
            simplifiedExpression += current;
    }
    return simplifiedExpression;
}

string parseSEXP(const string& simplifiedSEXP) {

}

// TODO : Pretty print the s-expression
void printSEXP(const string& parsedExpression) {
    cout << parsedExpression;
}
