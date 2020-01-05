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
        cout << "Could not open the directory, change the directory name in the source code";
        exit(EXIT_FAILURE);
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

// TODO : Add "" implementation and UTF-8
string simplifySEXP(const string& sexpExpression) {
    string simplifiedExpression;
    for (unsigned int i = 0; i < sexpExpression.length() - 1; i++) {
        char current = sexpExpression[i];
        char next = sexpExpression[i + 1];
        // next is a printable and correct character between a comma and the letter z
        if ((current == PARENTHESE_RIGHT || current == PARENTHESE_LEFT || current == SPACE) &&
            START_CORRECT_CHAR <= next && next <= END_CORRECT_CHAR)
            simplifiedExpression += SPACE;
        // current is a printable and correct character
        else if (START_CORRECT_CHAR <= current && current <= END_CORRECT_CHAR)
            simplifiedExpression += current;
    }
    return simplifiedExpression;
}

string extractStringFromSEXP(const string& simplifiedSEXP, const string& element) {
    string copySEXP = simplifiedSEXP;
    unsigned int pos = simplifiedSEXP.find(element) + element.length() + 1; // + 1 because of one space char
    unsigned int n = (copySEXP.erase(0, pos)).find(SPACE);
    return simplifiedSEXP.substr(pos, n);
}

Capture parseSEXP(const string& simplifiedSEXP) {
    Capture capture;
    capture.header = extractStringFromSEXP(simplifiedSEXP, HEADER);
    capture.id = extractStringFromSEXP(simplifiedSEXP, ID);
    capture.name =  extractStringFromSEXP(simplifiedSEXP, NAME);
    capture.timestamp = extractStringFromSEXP(simplifiedSEXP, TIMESTAMP);
    capture.settings.mode =  extractStringFromSEXP(simplifiedSEXP, MODE);
    capture.settings.frequency = stoi(extractStringFromSEXP(simplifiedSEXP, FREQUENCY));
    capture.settings.fps = stoi(extractStringFromSEXP(simplifiedSEXP, FPS));
    capture.settings.exposure = stoi(extractStringFromSEXP(simplifiedSEXP, EXPOSURE));
    capture.settings.gain_r = stof(extractStringFromSEXP(simplifiedSEXP, GAIN_R));
    capture.settings.gain_g = stof(extractStringFromSEXP(simplifiedSEXP, GAIN_G));
    capture.settings.gain_b = stof(extractStringFromSEXP(simplifiedSEXP, GAIN_B));
    capture.coordinates.latitude = stof(extractStringFromSEXP(simplifiedSEXP, LATITUDE));
    capture.coordinates.longitude = stof(extractStringFromSEXP(simplifiedSEXP, LONGITUDE));
    capture.coordinates.altitude = stof(extractStringFromSEXP(simplifiedSEXP, ALTITUDE));
    return capture;
}

// TODO : Pretty print the s-expression
void printSEXP(const Capture& parsedExpression) {
    cout    << "Capture " << OBJECT_T << VALUE << endl
            << TABS << HEADER << STRING_T << VALUE << parsedExpression.header << endl
            << TABS << ID << STRING_T << VALUE << parsedExpression.id << endl
            << TABS << NAME << STRING_T << VALUE << parsedExpression.name << endl
            << TABS << TIMESTAMP << STRING_T << VALUE << parsedExpression.timestamp << endl
            << TABS << "capture_settings " << OBJECT_T << VALUE << endl
                << TABS << TABS << MODE << STRING_T << VALUE << parsedExpression.settings.mode << endl
                << TABS << TABS << FREQUENCY << UINT_T << VALUE << parsedExpression.settings.frequency << endl
                << TABS << TABS << FPS << UINT_T << VALUE << parsedExpression.settings.fps << endl
                << TABS << TABS << EXPOSURE << UINT_T << VALUE << parsedExpression.settings.exposure << endl
                << TABS << TABS << GAIN_R << FLOAT_T << VALUE << parsedExpression.settings.gain_r << endl
                << TABS << TABS << GAIN_G << FLOAT_T << VALUE << parsedExpression.settings.gain_g << endl
                << TABS << TABS << GAIN_B << FLOAT_T << VALUE << parsedExpression.settings.gain_b << endl
            << TABS << "coordinates " << OBJECT_T << VALUE << endl
                << TABS << TABS << LATITUDE << FLOAT_T << VALUE << parsedExpression.coordinates.latitude << endl
                << TABS << TABS << LONGITUDE << FLOAT_T << VALUE << parsedExpression.coordinates.longitude << endl
                << TABS << TABS << ALTITUDE << FLOAT_T << VALUE << parsedExpression.coordinates.altitude<< endl;
}
