# Problem

Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

```
matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
```
Note: 
You may assume k is always valid, 1 ≤ k ≤ n<sup>2</sup> .

# Solution

The first approach is to use the same method as that in [Problem 23](../023%20Merge%20k%20Sorted%20Lists). The time complexity is O(klog(n)). Since k can be as large as n<sup>2</sup>, this time complexity can be concluded as O(n<sup>2</sup>log(n)).

The second approach is to use two-layer binary search. The outter layer is use to indicate the final answer. The starting ending points are matrix[0][0] and matrix[n-1][n-1]. The inner layer is to find how many numbers in each row is not larger than the mid-point in the outter layer. The time complexity can be O(nlog(n)log(INT_MAX-INT_MIN)). 

That is to say, when n is larger than 30, the later approach is preferrable. If n and k are very large, we can say that the optimal time complexity can be O(nlog(n)).

# Running Time

- cpp version: 120 ms (001.cpp)
- cpp version: 56 ms (002.cpp)
