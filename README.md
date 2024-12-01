# Rock Paper Scissors Tournament

- Total number of creatures per team is based on user input, and the number of
total creatures will be based on user
input. The creatures will then be sorted into teams until each team is even.
- Within each match, each creature will play against each creature from the other
team. Each time a creature wins a
game of rps, a point will be added to it's team's point tally.
- round robin style. Each team will play against each team. Within each match,
teams will generate points by the
method explained above. At the end of the tournament, whichever team has amassed
the greatest number of points will
be declared the victor. In the even of a tie between two or more teams, they will
face off in another round
robin, until a winner is declared.
A round robin can be implemetned by using a vector of all of the teams. This vector
can then be put in a loop in
which a team will be removed from a temporary vector and them play against every
team still inside the vector.
Repeating this until there is only one team left in the vector will ensure that
every team has played agaisnt every
team once.
- There will be a function called run_tourney. It will take an input of the nubmer
of creatures and the number of
teams according to the user's input.

