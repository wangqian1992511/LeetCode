001.cpp (9ms):
001.py (56ms):

We should first focus on the contribution of a certain number "x" to the number of trailing zeros of "n!". It is not difficult to observe that if "5^k" is a factor of "x", then it will add "k" zeros to the end of "n!". A naive O(n) solution cannot pass the test. Given the number "n", we can derive how many numbers can be divided by "5^k" by "n / 5^k". This idea leads to a solution with time complexity of O(log_5(n)).

