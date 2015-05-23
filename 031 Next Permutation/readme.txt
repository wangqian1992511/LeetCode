001.cpp (12ms):

Scan from back to end. As long as we find an element nums[i] > nums[i-1], we know that nums[i-1] should be updated to the smallest element larger than it among {nums[i], nums[i+1], ..., nums[n-1]}. Then we should sort the elements {nums[i], nums[i+1], ..., nums[n-1]}. Notice that if we cannot find such an element nums[i] > nums[i-1], then we should sort the whole array.

The so-called sort is not a real sorting. What we should do is just to reverse the elements in the vector directly. Though it seems that there is a three-layer loop, the inner part will only be visited once. So, the time complexity is O(n).
