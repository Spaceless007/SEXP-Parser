using namespace std;

const string ERR_FILE_MESSAGE = "Could not open the file\n";
const char PARANTHESE_LEFT = '(';
const char PARANTHESE_RIGHT = ')';
const char SPACE = ' ';
const char QUOTE = '"';
const char TAB = '\t';

string readFileSEXP(const string& fileName);

string parseSEXP(const string& sexpExpression);

void printSEXP(const string& parsedExpression);