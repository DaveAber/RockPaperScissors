all : RockPaperScissors

main RockPaperScissors : RockPaperScissors.cpp MythicalCreature.cpp MythicalCreature.h RPS_Game.cpp RPS_Game.h
	g++ -Wall -Wextra -pedantic RockPaperScissors.cpp MythicalCreature.cpp RPS_Game.cpp -o RockPaperScissors

tests/pet.test : tests/pet.test.cpp pet.cpp pet.h
	g++ -std=c++20 -Wall -Wextra -pedantic -I./ tests/pet.test.cpp pet.cpp -o tests/pet.test -lCatch2Main -lCatch2

run : RockPaperScissors
	./RockPaperScissors

test : tests/pet.test
	./tests/pet.test -s

test_quiet : tests/pet.test
	./tests/pet.test

clean :
	rm -f RockPaperScissors tests/pet.test

.PHONY : all run test test_quiet clean