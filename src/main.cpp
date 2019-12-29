#include <cstdio>
#include <cstdlib>
#include <string>
#include "sexp-parser.hpp"
using namespace std;

int main()
{
    // TODO : Make cin for the filename
    string fileName = "../examples/capture.sexp";
    string sexpExpression = readFileSEXP(fileName);
    string parsedExpression = parseSEXP(sexpExpression);
    printf("Here is the parsed s-expression\n");
    printSEXP(parsedExpression + '\n'+ '\n');

	return EXIT_SUCCESS;
}