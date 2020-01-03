/***********************************************************************************
 * @brief The header file containing every functions to parse an s-expression from a file
 * @author Nathanaël Beaudoin-Dion
 * @date December 27th 2019
 ***********************************************************************************/

/// NAMESPACE
using namespace std;

/// CONSTANTS FOR THE PARSER

const char PARENTHESE_LEFT = '(';
const char PARENTHESE_RIGHT = ')';
const char SPACE = ' ';
const char QUOTE = '"'; // TODO : To implement
const char START_CORRECT_CHAR = ',';
const char END_CORRECT_CHAR = 'z';

static const char* S_EXPRESSIONS_DIRECTORY = "../examples/";

// to explicitly tell the type of each element of the s-expression
const string DATA_TYPE_ELEMENT = "d:";
const string VALUE_ELEMENT = "v:";

/// FUNCTIONS FOR THE PARSER

/** Function : string findFileSEXP(const char*)
 *  @brief Parse and print the file names in a directory and let the user choose one
 *  @param the name of the directory containing the s-expression files
 *  @return the name of the file selected by the user contained in a string
 *  @note
     * In c++ 17, there is an official way to do it with std::filesystem, but through my research I found that some
     * compilers don't support this feature, which is why I didn't use std::filesystem
     * see https://stackoverflow.com/questions/612097/how-can-i-get-the-list-of-files-in-a-directory-using-c-or-c/37494654#37494654
 **/
string findFileSEXP(const char* directoryName);

/** Function : string readFileSEXP(const string&)
 *  @brief Read a file containing an s-expression and returns it
 *  @param the name of the file to read
 *  @return the s-expression of the file contained in a string
 **/
string readFileSEXP(const string& fileName);

/** Function : string simplifySEXP(const string&)
 *  @brief Removes incorrect characters of an s-expression and returns the simplified s-expression
 *  @param the raw s-expression
 *  @return the simplified s-expression contained in a string
 **/
string simplifySEXP(const string& sexpExpression);

/** Function : string parseSEXP(const string&)
 *  @brief Parses a simplified s-expression and returns the parsed s-expression
 *  @param the simplified s-expression
 *  @return the parsed s-expression contained in a string
 **/
string parseSEXP(const string& simplifiedSEXP);

/** Function : void printSEXP(const string&)
 *  @brief Print an s-expression on the standard output
 *  @param the parsed s-expression
 **/
void printSEXP(const string& parsedExpression);
