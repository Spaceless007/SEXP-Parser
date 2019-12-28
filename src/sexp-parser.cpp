#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <assert.h>
#include <algorithm>

using namespace std;

string readFileSEXP(const string fileName) {
    ifstream file;
    file.open(fileName);
    string fileTextTemp;
    string lineTemp;
    if (file.is_open()) {
        while (getline(file, lineTemp)) {
            fileTextTemp += lineTemp;
        }
        // fileTextTemp.erase(std::remove(fileTextTemp.begin(), fileTextTemp.end(), ' '), fileTextTemp.end());
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