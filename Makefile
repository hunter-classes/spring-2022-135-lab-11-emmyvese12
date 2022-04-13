main: main.o profile.o
	g++ -o main main.o profile.o

tests: tests.o profile.o
	g++ -o tests tests.o profile.o

main.o: main.cpp profile.cpp profile.h
	g++ -c main.cpp

tests.o: tests.cpp doctest.h profile.h
	g++ -c tests.cpp

profile.o: profile.cpp profile.h
	g++ -c profile.cpp

clean:
	rm -f main tests main.o tests.o profile.o