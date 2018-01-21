# A very simple makefile.

unit_tests: tests/test_wordfind.cpp src/wordfind.cpp src/wordfind.h
	g++ -o $@ $^ -Isrc/ -lUnitTest++
	./unit_tests

clean:
	rm unit_tests
