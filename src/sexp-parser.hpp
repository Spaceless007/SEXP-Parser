/***********************************************************************************
 * @brief The header file containing every functions to parse an s-expression from a file
 * @author Nathanaël Beaudoin-Dion
 * @date December 27th 2019
 ***********************************************************************************/

/// NAMESPACE
using namespace std;

/// CONSTANTS

static const char* S_EXPRESSIONS_DIRECTORY = "../examples/";

const char PARENTHESE_LEFT = '(';
const char PARENTHESE_RIGHT = ')';
const char SPACE = ' ';
const char QUOTE = '"'; // TODO : To implement
const char TABS = '\t';
const char START_CORRECT_CHAR = ',';
const char END_CORRECT_CHAR = 'z';

const string HEADER = "Capture";
const string ID = "id";
const string NAME = "name";
const string TIMESTAMP = "timestamp";
const string MODE = "mode";
const string FREQUENCY = "frequency";
const string FPS = "fps";
const string EXPOSURE = "exposure";
const string GAIN_R = "gain_r";
const string GAIN_G = "gain_g";
const string GAIN_B = "gain_b";
const string LATITUDE = "latitude";
const string LONGITUDE = "longitude";
const string ALTITUDE = "altitude";

const string STRING_T = " type:string";
const string UINT_T = " type:uint";
const string FLOAT_T =" type:float";
const string OBJECT_T = " type:object";
const string VALUE = " value:";

/// STRUCTS

struct Settings {
    string mode;
    unsigned int frequency;
    unsigned int fps;
    unsigned int exposure;
    float gain_r;
    float gain_g;
    float gain_b;
};

struct Coordinates {
    float latitude;
    float longitude;
    float altitude;
};

struct Capture {
    string header;
    string id;
    string name;
    string timestamp;
    Settings settings;
    Coordinates coordinates;
};

/// FUNCTIONS

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

/** Function : string extractStringFromSEXP(const string&, const string&);
 *  @brief Extracts a string from an s-expression simplified
 *  @params
    * simplifiedSEXP: the simplified s-expression
    * element: the element from the s-expression to find it's value
 *  @return the parsed s-expression contained in a Capture struct
 **/
string extractStringFromSEXP(const string& simplifiedSEXP, const string& element);

/** Function : string parseSEXP(const string&)
 *  @brief Parses a simplified s-expression and returns the parsed s-expression
 *  @param the simplified s-expression
 *  @return the parsed s-expression contained in a Capture struct
 **/
Capture parseSEXP(const string& simplifiedSEXP);

/** Function : void printSEXP(const Capture&)
 *  @brief Print an s-expression on the standard output
 *  @param the parsed s-expression
 **/
void printSEXP(const Capture& parsedExpression);
