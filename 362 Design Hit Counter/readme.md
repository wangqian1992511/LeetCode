# Problem

Design a hit counter which counts the number of hits received in the past 5 minutes.

Each function accepts a timestamp parameter (in seconds granularity) and you may assume that calls are being made to the system in chronological order (ie, the timestamp is monotonically increasing). You may assume that the earliest timestamp starts at 1.

It is possible that several hits arrive roughly at the same time.

Example:

```
HitCounter counter = new HitCounter();

// hit at timestamp 1.
counter.hit(1);

// hit at timestamp 2.
counter.hit(2);

// hit at timestamp 3.
counter.hit(3);

// get hits at timestamp 4, should return 3.
counter.getHits(4);

// hit at timestamp 300.
counter.hit(300);

// get hits at timestamp 300, should return 4.
counter.getHits(300);

// get hits at timestamp 301, should return 3.
counter.getHits(301); 
```
Follow up:
What if the number of hits per second could be very large? Does your design scale?

# Solution
Two queue are used to maintain the timestamps and the number of hit per second. 

When there is a new hit, we either push new elements to these two queues (new time stamp) or update the value of latest hit number (old time stamp). When the query comes, we update the two queues with pop operation.

Even if the number of hits per second could be very large, the memory complexity is the same as the case when there is at most one hit per second.

# Running Time

- cpp version: 0 ms (001.cpp)
