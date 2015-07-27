001.cpp (40ms):

Divide this problem into two sub-problems, with the constraint of "children with a higher rating get more candies than their left/right neighbors." Then, perform linear scanning twice to get the minimum candies under these two conditions. For any child, the maximum of these two values is the number of candies given in the original problem.