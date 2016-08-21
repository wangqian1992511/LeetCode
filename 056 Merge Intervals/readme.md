# Problem

Given a collection of intervals, merge all overlapping intervals.

For example,
Given ``[1,3],[2,6],[8,10],[15,18]``,
return ``[1,6],[8,10],[15,18]``.

# Solution

Sort the intervals according to the ascending start time slot and decreasing end time slot. Then use linear scanning to merge consecutive overlapped intervals. The time complexity is O(nlog(n)).

# Running Time

- cpp version: 20 ms (001.cpp)