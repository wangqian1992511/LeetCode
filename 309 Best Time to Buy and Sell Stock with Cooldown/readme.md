# Problem

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

```
prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]
```
# Solution

Due to the cooldown, we should maintain two more variables. The first variable is used to record the second highest profit ending with a selling; the second variable is used to record the last selling date to achieve the maximum profit.

The transition function is:

```
bestBuy = max{bestBuy, bestSell - prices[i]} if sellDay is not yesterday
bestBuy = max{bestBuy, secondSell - prices[i]} if sellDay is yesterday
bestSell = max{bestSell, bestBuy + prices[i]}
```

The variable secondSell is updated only when bestSell is updated.

# Running Time

- cpp version: 8 ms (001.cpp)
