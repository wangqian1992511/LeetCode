# Problem

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

# Solution

This problem is the ideal case of achieving the maximum profit in the real stock market. We should always try to buy at the valley and sell at the peak. 

But we do not really need to implement the code to find valley and peak. We just need to notice that, under this circumstance, we can obtain all increasing profits between two consecutive days. The time complexity is O(n).

# Running Time

- cpp version: 8 ms (001.cpp)
