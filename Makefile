all : RockPaperScissors

main RockPaperScissors : RockPaperScissors.cpp MythicalCreature.cpp MythicalCreature.h \
	RPS_Game.cpp RPS_Game.h Tournament.cpp Tournament.h
	g++ -g -Wall -Wextra -pedantic RockPaperScissors.cpp MythicalCreature.cpp RPS_Game.cpp \
	Tournament.cpp -o RockPaperScissors

run : RockPaperScissors
	./RockPaperScissors

clean :
	rm -f RockPaperScissors

.PHONY : all run clean