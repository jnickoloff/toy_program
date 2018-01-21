
unit_tests: tests/test_wordfind.cpp src/wordfind.cpp src/wordfind.h
	g++ -o $@ $^ -Isrc/ -lUnitTest++

