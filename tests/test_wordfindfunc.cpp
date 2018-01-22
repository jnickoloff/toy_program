#include "UnitTest++/UnitTest++.h"
#include "wordfindfunc.h"


SUITE(iteratorTests)
{
    // Corner cases
    TEST(returnsEmptyVectorIfCantFindCharacter)
    {
        strings words = findWordsWithChar("Hello, my name is Benjamin Smith.", 'z');
        CHECK_EQUAL(0, words.size());
    }

    TEST(returnsEmptyVectorIfNoSentenceSupplied)
    {
        strings words = findWordsWithChar("", 'a');
        CHECK_EQUAL(0, words.size());
    }

    TEST(findsLastWordOfSentence)
    {
        strings words = findWordsWithChar("yarp", 'a');
        CHECK_EQUAL("yarp", words[0]);
    }


    struct ForBasicFunctionality
    {
        ForBasicFunctionality()
        {
            words = findWordsWithChar("Hello, my name is Benjamin Smith.", 'a');
        }

        strings words;
    };

    TEST_FIXTURE(ForBasicFunctionality, findsFirstWord)
    {
        CHECK_EQUAL("name", words[0]);
    }

    TEST_FIXTURE(ForBasicFunctionality, findsSecondWord)
    {
        CHECK_EQUAL("Benjamin", words[1]);
        CHECK_EQUAL(2, words.size());
    }


    struct ForPunctuation
    {
        ForPunctuation()
        {
            words = findWordsWithChar("Hello, my name is Benjamin Blarg.", 'l');
        }

        strings words;
    };

    TEST_FIXTURE(ForPunctuation, doesNotIncludeCommas)
    {
        CHECK_EQUAL("Hello", words[0]);
    }

    TEST_FIXTURE(ForPunctuation, doesNotIncludePeriods)
    {
        CHECK_EQUAL("Blarg", words[1]);
    }
}
