# A very simple makefile.

unittests: tests/test_wordfindstream.cpp tests/test_wordfindfunc.cpp src/wordfindstream.cpp  src/wordfindstream.h src/wordfindfunc.cpp src/wordfindfunc.h
	g++ -o $@ $^ -Isrc/ -lUnitTest++ -std=c++11 -g
	./$@

wordfinder: src/main.cpp src/wordfindfunc.cpp src/wordfindfunc.h
	g++ -o $@ $^ -Isrc/ -std=c++11 -g

clean:
	rm -f unittests
	rm -f wordfinder
