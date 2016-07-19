# Problem

Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:

1. You must not modify the array (assume the array is read only).
2. You must use only constant, O(1) extra space.
3. Your runtime complexity should be less than O(n<sup>2</sup>).
4. There is only one duplicate number in the array, but it could be repeated more than once.

# Solution

We can use the binary search. In each iteration, we take the mid point of the current interval, and use O(n) time to check whether the duplicate is greater or smaller than this mid point. If the duplicate is greater, there will be more elements larger than the mid point in this interval. The time complexity is O(nlog(n)).

# Running Time

- cpp version: 28 ms (001.cpp)
