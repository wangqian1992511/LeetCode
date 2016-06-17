# Problem

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

```
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
```


# Solution

Straightforward O(n) solution is applied. Pay attention to the situation when:

1. the length of two list are distinct

	```
	Input: (2) + (5 -> 6 -> 4)
	Output: 7 -> 6 -> 4
	```

2. there is one more remaining digit to be linked to the tail

	```
	Input: (2 -> 4 -> 5) + (5 -> 6 -> 4)
	Output: 7 -> 0 -> 0 -> 1
	```

# Running Time

- cpp version: 40 ms (001.cpp)
- python version: 164 ms (001.py)
