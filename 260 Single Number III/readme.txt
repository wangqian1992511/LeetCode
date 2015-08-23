001.cpp (20ms):

It's easy to get a XOR b. Then use the lowbit operation, the get the lowest bit of this number. This bit can only be provided by one of these two numbers. Use the XOR operation again in the whole array to get one number. The other one is now easy to obtain.