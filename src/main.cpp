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
    string fileName = findFileSEXP(S_EXPRESSIONS_DIRECTORY);
    string sexpExpression = readFileSEXP(fileName);
    string parsedExpression = simplifySEXP(sexpExpression);
    cout << "Here is the parsed s-expression: " << endl;
    printSEXP(parsedExpression);

	return EXIT_SUCCESS;
}
