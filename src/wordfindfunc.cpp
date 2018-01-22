#include "wordfindfunc.h"

#include <regex>
#include <algorithm>
#include <sstream>


using namespace std;


strings findWordsWithChar(string sentence, char charToSeek)
{
    ostringstream regexStream;
    regexStream << "(\\w*" << charToSeek <<  "\\w*)([ .,!?]+|$)";

    regex re(regexStream.str());
    sregex_iterator begin(sentence.begin(), sentence.end(), re);
    sregex_iterator end;

    strings finalWords;
    transform(begin, end, back_inserter(finalWords), [] (const smatch& m) { return m.str(1); });

    return finalWords;
}

