/***********************************************************************************
 * @brief The header file containing every functions to parse an s-expression from a .sexp file
 * @author Nathanaël Beaudoin-Dion
 * @date December 27th 2019
 ***********************************************************************************/

/// NAMESPACE
using namespace std;

/// CONSTANTS FOR THE PARSER

const string ERR_FILE_MESSAGE = "Could not open the file\n";
const char PARENTHESE_LEFT = '(';
const char PARENTHESE_RIGHT = ')';
const char SPACE = ' ';
const char QUOTE = '"';
const char TAB = '\t';

/// FUNCTIONS FOR THE PARSER

/** Function : string readFileSEXP(const string&)
 *  @brief Read a file containing an s-expression and returns it
 *  @param the name of the file to read
 *  @return the s-expression of the file contained in a string
 **/
string readFileSEXP(const string& fileName);

/** Function : string parseSEXP(const string&)
 *  @brief Parses an s-expression and returns the parsed s-expression
 *  @param the raw s-expression
 *  @return the parsed s-expression contained in a string
 **/
string parseSEXP(const string& sexpExpression);

/** Function : void printSEXP(const string&)
 *  @brief Print an s-expression on the standard output
 *  @param the parsed s-expression
 **/
void printSEXP(const string& parsedExpression);
