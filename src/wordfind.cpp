#include "wordfind.h"
#include <algorithm>

using namespace std;

WordFindStream::WordFindStream(string sentence, char charToSeek) :
    sentence(sentence),
    charToSeek(charToSeek)
{
}

WordFindStream& WordFindStream::operator>>(string& str)
{
    string currentWord;

    while (! sentence.eof())
    {
        sentence >> currentWord;

        if (find(currentWord.begin(), currentWord.end(), charToSeek) != currentWord.end())
        {
            str = currentWord;
            break;
        }
    }

    return *this;
}

