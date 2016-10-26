# Problem

Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9

Output: index1=1, index2=2

# Solution

Place two pointers on each end and make them move towards each other. If the sum is smaller than target, then move the front pointer; otherwise, move the back pointer.

# Running Time

- cpp version: 6 ms (001.cpp)
