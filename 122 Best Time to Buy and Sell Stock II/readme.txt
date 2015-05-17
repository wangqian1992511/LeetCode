001.cpp (9ms):

Since we can buy and sell for several times, we want to obtain all the profits and avoid all the loss. Generally, we want to find every peaks and valleys and accumulate the difference between adjacent peak and valley together. This is just equivalent to accumulate all the difference between the prices of the adjacent days, if the price on the latter day is higher. Time complexity is O(n).
