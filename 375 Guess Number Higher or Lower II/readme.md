# Problem

We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.

However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.

Example:

```
n = 10, I pick 8.

First round:  You guess 5, I tell you that it's higher. You pay $5.
Second round: You guess 7, I tell you that it's higher. You pay $7.
Third round:  You guess 9, I tell you that it's lower. You pay $9.

Game over. 8 is the number I picked.

You end up paying $5 + $7 + $9 = $21.
```
Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.

Follow up:
What if the number of hits per second could be very large? Does your design scale?

# Solution
This is a DP problem with the transition funciton:

```
dp[i][j] = min{max{dp[i][k-1], dp[k+1][j]} + k}
```

Here, dp[i][j] is the maximum loss when guessing a number between i and j. If we concentrated on minimizing the expected loss, the transition function will be:

```
dp[i][j] = min{dp[i][k-1] / (k - i) + dp[k+1][j] / (j - k) + k}
```

# Running Time

- cpp version: 28 ms (001.cpp)
