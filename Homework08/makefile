program.o: program.exe
	./program.exe
program.exe: Simulation.o
	g++ Simulation.o -o program.exe
Simulation.o: Simulation.cpp
	g++ -c -std=c++11 Simulation.cpp
