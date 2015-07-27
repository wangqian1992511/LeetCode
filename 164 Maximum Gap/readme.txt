001.cpp (16ms):

Sort and then check the difference between adjacent elements.

002.cpp (20ms):

Use the thought of bucket sorting. Suppose that there are "n" buckets, with the previous "n-1" buckets having a length of "(max - min) / (n-1)". From the pigeon hole principle, we know that this is the lower bound of the final answer. We only maintain the minimum and maximum in each bucket. The only thing to do is to find the maximum difference between the maximum and minimum value of two adjacent buckets.
