run: main.o Executive.o Dice.o crapsDriver.o
	g++ -std=c++11 -g -Wall main.o Executive.o Dice.o crapsDriver.o -o run

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Dice.o: Dice.h Dice.cpp
	g++ -std=c++11 -g -Wall -c Dice.cpp

Executive.o: Executive.h Executive.cpp Dice.h Dice.cpp crapsDriver.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp Dice.cpp crapsDriver.cpp

crapsDriver.o: crapsDriver.h crapsDriver.cpp
	g++ -std=c++11 -g -Wall -c crapsDriver.cpp

clean:
	rm *.o run
