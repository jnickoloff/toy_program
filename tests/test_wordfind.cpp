#include "UnitTest++/UnitTest++.h"
#include "wordfind.h"


TEST(Sanity) 
{
   CHECK_EQUAL(1, 1);
}

TEST(WordFindInit)
{
    //WordFind* a = new WordFind();
    //a->foo();
    
    WordFind a;
    a.foo();
}

int main(int, const char *[])
{
   return UnitTest::RunAllTests();
}
