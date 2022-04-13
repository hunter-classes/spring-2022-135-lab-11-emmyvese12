main: main.o profile.o
	g++ -o main main.o profile.o

tests: tests.o
	g++ -o tests tests.o

main.o: main.cpp profile.cpp profile.h
	g++ -std=c++11 -c main.cpp

tests.o: tests.cpp doctest.h profile.h
	g++ -std=c++11 -c tests.cpp

profile.o: profile.cpp profile.h
	g++ -std=c++11 -c profile.cpp

clean:
	rm -f main main.o tests.o profile.o