# Problem

Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.

First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?

# Solution

A simple idea is to use the counting sort (001.cpp). If we woule like to avoid using two for loops, we can use three pointers (002.cpp). 

Each pointer is used to indicate the leftmost index of a particular number. As long as we find a inversion, we should conduct a swapping and update the the two pointers.


# Running Time

- cpp version: 4 ms (001.cpp)
- cpp version: 4 ms (002.cpp)
