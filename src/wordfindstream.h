#ifndef WORDFINDSTREAM_H
#define WORDFINDSTREAM_H

#include <string>
#include <sstream>

class WordFindStream
{
    public:
        WordFindStream(std::string sentence, char charToSeek);
        WordFindStream& operator>>(std::string& str);

    private:
        std::istringstream sentence;
        char charToSeek;
};

#endif
