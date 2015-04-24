001.cpp (16ms):

After overflow is considered, this problem becomes a little bit interesting. This first step is to eliminate the zeros at the end. This will not lead to the overflow obviously. If there is an overflow, we cannot recover the original input by reversing the reversed number. Thus, we consider to apply a two-pass approach. Since the input number is always a 32-bit integer with at most 10 digits, the time complexity is O(1).
