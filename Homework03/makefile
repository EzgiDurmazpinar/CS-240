Fraction.exe: Fraction.o fractionTester.o
	g++ Fraction.o fractionTester.o -o Fraction.exe

Fraction.o: Fraction.cpp Fraction.h
	g++ -c -std=c++11 Fraction.cpp
	
fractionTester.o: Fraction.cpp Fraction.h
	g++ -c -std=c++11 fractionTester.cpp

clean:
	rm *.o *.exe




