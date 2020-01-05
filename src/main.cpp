/***********************************************************************************
 * @brief The main source file containing the main function for the s-expression parser
 * @author Nathanaël Beaudoin-Dion
 * @date December 27th 2019
 ***********************************************************************************/

/// STANDARD INCLUDES
#include <cstdlib>
#include <string>
#include <iostream>

/// SEXP-PARSER INCLUDES
#include "sexp-parser.hpp"

/// NAMESPACE
using namespace std;

/// IMPLEMENTATION OF MAIN FUNCTION
int main()
{
    string res;
    do {
        // Parse one file
        string fileName = findFileSEXP(S_EXPRESSIONS_DIRECTORY);
        string sexpExpression = readFileSEXP(fileName);
        string simplifiedExpression = simplifySEXP(sexpExpression);
        Capture parsedExpression = parseSEXP(simplifiedExpression);
        cout << "Here is the parsed s-expression: " << endl;
        printSEXP(parsedExpression);

        // Check if user want to parse another file
        cout << endl << "Do you want to parse another file? [Y/n]" << endl;
        cin >> res;
    } while (res[0] == 'Y');

    return EXIT_SUCCESS;
}
