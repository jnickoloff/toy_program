#include "wordfindfunc.h"
#include <iostream>
#include <iterator>
#include <sstream>

using namespace std;


char stringToChar(string oneCharString)
{
    char returnChar;
    istringstream convStream(oneCharString);
    convStream >> returnChar;
    return returnChar;
}

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        cout << "Usage: wordfinder \"<sentence>\" <char>" << endl;
        return 1;
    }

    string sentence(argv[1]);
    char charToSeek = stringToChar(argv[2]);

    strings words = findWordsWithChar(sentence, charToSeek);

    ostream_iterator<string> mycout(cout, " ");
    copy(begin(words), end(words), mycout);

    cout << endl;

    return 0;
}
