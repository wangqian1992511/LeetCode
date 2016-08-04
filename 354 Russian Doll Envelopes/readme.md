# Problem

You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Example:
Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

# Solution

We can first sort all the envelopes according to their ascending width and decending height. Then the only thing to do is to find the longest increasing height in this new list of envelopes, with the method in [Problem 300](../300%20Longest%20Increasing%20Subsequence). The time complexity is O(nlog(n)).

One may also think using a method using topological sort, similar to that in [Problem 329](../329%20Longest%20Increasing%20Path%20in%20a%20Matrix). But this method with a time complexity of O(n<sup>2</sup>) is too expensive. The reasong is that, in this problem, the graph we construct is a dense graph (actually a complete graph).

# Running Time

- cpp version: 44 ms (001.cpp)
- cpp version: TLE (002.cpp)
