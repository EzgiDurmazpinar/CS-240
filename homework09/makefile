program.o: program.exe
	./program.exe
program.exe: TestMap.o
	g++ TestMap.o -o program.exe
TestMap.o: TestMap.cpp
	g++ -c -std=c++11 TestMap.cpp
