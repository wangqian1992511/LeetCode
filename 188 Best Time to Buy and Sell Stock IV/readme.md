# Problem

Say you have an array for which the i-th element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

# Solution

This is a DP problem. The transfer function is:

```
sell[i,k] = max{sell[i-1, k], buy[i-1, k] + prices[i]}
buy[i,k] = max{buy[i-1, k], sell[i-1, k - 1] - prices[i]}
```

The first trick point is to reduce the time complexity. From this transfer function, we can implement an algorithm with O(nk) time complexity. But, when k is larger than n/2, the limit of transactions become meaningless. In this case, we can use the O(n) method in [Problem 122](../122%20Best%20Time%20to%20Buy%20and%20Sell%20Stock%20II) directly.

The second trick point is to figure out the correct direction and bound of the loop for variable k. We can find that at the i-th day, we can have at most performed (i+2)/2 buying and (i+1)/2 selling. Further, if we update these two function with i increasing and k decreasing, we can ignore the i dimension when coding. Thus, reduce the space complexity to O(k).

The time complexity is O(n<sup>2</sup>).

# Running Time

- cpp version: 12 ms (001.cpp)
