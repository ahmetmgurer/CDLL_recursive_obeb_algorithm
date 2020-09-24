hepsi: derle calistir

derle:
	g++ -I ./include -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include -o ./lib/Iter.o -c ./src/Iter.cpp
	g++ -I ./include -o ./lib/CDLL.o -c ./src/CDLL.cpp
	g++ -I ./include/ -o ./bin/Main ./lib/Node.o ./lib/Iter.o ./lib/CDLL.o ./src/Main.cpp
	
calistir:
	./bin/Main