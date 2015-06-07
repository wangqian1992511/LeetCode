001.cpp (20ms):

Use two stacks to record the information we need to find all the possible maximal rectangles, those that are not entirely covered by one other rectangle. More specifically, "l" records the leftmost index of such a rectangle, and "r" records the rightmost index of such a consecutive height at present, when we are linearly scanning the vector "height". The time complexity is O(n).

e.g.

h: 2 3 4 5 4 3 2 1
r: 0
l: 0
a: 0

->

h: 2 3 4 5 4 3 2 1
r: 0 1
l: 0 1
a: 0

->

h: 2 3 4 5 4 3 2 1
r: 0 1 2
l: 0 1 2
a: 0

->

h: 2 3 4 5 4 3 2 1
r: 0 1 2 3
l: 0 1 2 3
a: 0

->

h: 2 3 4 5 4 3 2 1
r: 0 1 x x 4
l: 0 1 2 x x
a: 5

->

h: 2 3 4 5 4 3 2 1
r: 0 x x x x 5
l: 0 1 x x x x
a: 12

->

h: 2 3 4 5 4 3 2 1
r: x x x x x x 6
l: 0 x x x x x x
a: 15

->

h: 2 3 4 5 4 3 2 1
r: x x x x x x x 7
l: x x x x x x x 0
a: 15

By now, we notice that we can add a special height -1 at first to the end of the vector "height" to deal with the remaining heights not discussed yet.

->

h: 2 3 4 5 4 3 2 1 -1
r: x x x x x x x x 8
l: x x x x x x x x 0
a: 15

