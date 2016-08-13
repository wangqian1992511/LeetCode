# Problem

Shuffle a set of numbers without duplicates.

Example:

```
// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();
```

# Solution

Determine the element at each index reversely. When we are determing the element at index i, we should pick an arbitrary element from nums[0..i]. By math induction, we can find that the probability for any element to be placed on any index is 1/n.

# Running Time

- cpp version: 412 ms (001.cpp)
