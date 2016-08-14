# Problem

Given a nested list of integers represented as a string, implement a parser to deserialize it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Note: You may assume that the string is well-formed:

String is non-empty.
String does not contain white spaces.
String contains only digits 0-9, [, - ,, ].
Example 1:

```
Given s = "324",

You should return a NestedInteger object which contains a single integer 324.
```
Example 2:

```
Given s = "[123,[456,[789]]]",

Return a NestedInteger object containing a nested list with 2 elements:

1. An integer containing value 123.
2. A nested list containing two elements:
    i.  An integer containing value 456.
    ii. A nested list with one element:
         a. An integer containing value 789.
```

# Solution

Use a stack to maintain the level of nests. At first, we always put an empty nested integer on top of the stack. This can make the case of a single number to be easier to process.

When we find a "[", we always put a new empty nested integer on top of the stack. When we meet a ",", we should add the current number to the top nested integer. When we get a "]", we will pop the top nested integer and then add it to the new top nested integer. The remaining job will be the same as parsing a number.

# Running Time

- cpp version: 40 ms (001.cpp)