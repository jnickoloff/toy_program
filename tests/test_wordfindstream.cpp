#include "UnitTest++/UnitTest++.h"
#include "wordfindstream.h"

using namespace std;

SUITE(stream)
{

    struct Fixture
    {
        Fixture() :
            finder("Hello, my name is Benjamin Smith.", 'a')
        {}

        WordFindStream finder;
    };

    TEST_FIXTURE(Fixture, findsFirstWord)
    {
        string actual;
        finder >> actual ;
        CHECK_EQUAL("name", actual);
    }

    TEST_FIXTURE(Fixture, findsSecondWord)
    {
        string actual;
        finder >> actual;
        finder >> actual;
        CHECK_EQUAL("Benjamin", actual);
    }

    TEST(returnsEmptyStringIfCantFindCharacter)
    {
        WordFindStream finder("Hello, my name is Benjamin Smith.", 'z');
        string actual;
        finder >> actual;
        CHECK_EQUAL("", actual);
    }
}

int main(int, const char *[])
{
   return UnitTest::RunAllTests();
}
