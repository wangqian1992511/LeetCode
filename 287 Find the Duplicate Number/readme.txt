001.cpp (580ms):

It's not difficult to derive that if the duplicate number is t, then the lower bound and the upper of the sum of the whole vector should be "(2n+3-t)t/2" and "(t^2+t+n^2+n)/2" respectively. Then use the binary search to find the rough range of the target duplicate. After that, we can do some little adjustment to the number we found.
