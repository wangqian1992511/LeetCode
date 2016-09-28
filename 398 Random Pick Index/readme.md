# Problem

Given an array of integers with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.

Note:
The array size can be very large. Solution that uses too much extra space will not pass the judge.

Example:

```
int[] nums = new int[] {1,2,3,3,3};
Solution solution = new Solution(nums);

// pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
solution.pick(3);

// pick(1) should return 0. Since in the array only nums[0] is equal to 1.
solution.pick(1);
```

# Solution

Since we should avoid using too much memory, we have to spend more time in the pick method. This method has a time complexity of O(n). As long as we meet a candidate, we generate a random number. The candidate with the smallest random value will be returned.

# Running Time

- cpp version: 13 ms (001.cpp)