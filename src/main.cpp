#include "wordfindfunc.h"
#include <iostream>
#include <iterator>
#include <sstream>

using namespace std;


int main(int argc, char** argv)
{
    strings args(argv, argv + argc);

    if (args.size() != 3)
    {
        cout << "Usage: wordfinder \"<sentence>\" <char>" << endl;
        return 1;
    }

    string sentence(args[1]);
    istringstream s(args[2]);
    char charToSeek;
    s >> charToSeek;

    ostream_iterator<string> mycout(cout, " ");
    strings words = findWordsWithChar(sentence, charToSeek);
    copy(words.begin(), words.end(), mycout);

    cout << endl;

    return 0;
}
