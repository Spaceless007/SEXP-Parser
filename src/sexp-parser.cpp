#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <assert.h>

using namespace std;

string readFileSEXP(const string fileName) {
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
        cout << "Could not open the file\n";
        assert(file.is_open());
    }
    return fileTextTemp;
}
string parseSEXP(const string sexpExpression) {

}

void printSEXP(const string parsedExpression) {
    cout << parsedExpression;
}