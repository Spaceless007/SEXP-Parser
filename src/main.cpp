#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "sexp-parser.hpp"
using namespace std;

int main()
{
    // TODO : Make stdin for the filename
    string fileName = "../examples/capture.sexp";
    string sexpExpression = readFileSEXP(fileName);
//    string parsedExpression = parseSEXP(sexpExpression);
    printf("Here is the parsed s-expression\n");
    printSEXP(sexpExpression);
	return EXIT_SUCCESS;
}