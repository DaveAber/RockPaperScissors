all : main

main: main.cpp creature.cpp creature.h \
	rpsgame.cpp rpsgame.h tournament.cpp tournament.h
	g++ -g -Wall -Wextra -pedantic main.cpp creature.cpp rpsgame.cpp \
	tournament.cpp -o main

run : main
	./main

clean :
	rm -f main

.PHONY : all run clean