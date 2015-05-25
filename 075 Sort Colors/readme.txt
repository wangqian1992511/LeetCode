001.cpp (4ms):

Use three points to track the position for the next 0, 1 or 2 to be located in. Linearly scan the whole array, put the element in the correct position according to its corresponding pointer, and update the points so that p[2] >= p[1] >= p[0] always holds true.
