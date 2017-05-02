test: program.out
	./program.out
	
program.out: program.o 
	g++ program.o -o program.out

program.o: program.cpp
	g++ -c -std=c++11 program.cpp
	
clean:
	rm *.o *.out