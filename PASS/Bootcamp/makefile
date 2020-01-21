output: main.o client.o
	g++ main.o client.o -o output

main.o: main.cpp client.cpp
	g++ -c main.cpp client.cpp

client.o: client.cpp
	g++ -c client.cpp

clean:
	-del *.o *.exe
