001.cpp (8ms):

The naive linear scan and check requires a time complexity of O(n).

002.cpp (7ms):

Since we can observe that the two sequences divided by the peak element are always monotonic, this property enable us to use binary search. The time complexity is now O(log(n)). Maybe the test case is not strong enough to show the advantage.
