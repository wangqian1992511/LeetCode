001.cpp (84ms):

Similar to two sum, use a hash table to record the sum a[0..i] appearing before. At the same time, maintain the running sum. Then finding a subarray sum k is equivalent to finding a[0..i] such that it is equal to sum - k.