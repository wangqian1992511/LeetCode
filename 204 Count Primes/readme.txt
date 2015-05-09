001.cpp (79ms):

Another fundamental problem comes. The only thing for us to do is to implement Sieve of Eratosthenes in this problem. The time complexity is O(nlog(log(n))). Notice that we do not need to record the exact prime numbers here. I record them here just for comparison with the next Sieve of Euler.

002.cpp (87ms):

Sieve of Euler has a linear time complexity of O(n). It seems that it is slower here, maybe because it requires may modular calculation and the test cases are not large enough. Each number will only be sieved by its largest nonself factor. The most interesting part is the second "break". If we find that "i = ap", where "p" is prime, then we can stop sieving for "i". If we still keep checking the next prime "p'", then the same number will be sieved again when "i" reaches "ap'".
