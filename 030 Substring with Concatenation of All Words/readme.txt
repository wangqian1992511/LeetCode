001.cpp (48ms):

Solve this problems with linear search. First, get the number of appearance of each word in the dictionary. Here, suppose that the length of each word in the dictionary is "k". When we arrive at a position worth checking, we keep checking every "k"-character long substrings, until:

1. we find an invalid one not in the dictionary;
2. we find that we have accumulated enough this kind of substring before;
3. we find a valid substring not reaching its number of apearance in the dictionary.

In case one, we should indicate the present position as visited, since we have known that this index cannot be one of those in the final answers. If this position "q" cannot be used, then it is obvious that "q-k", "q-2k", "q-3k", ..., "q-(m-1)k" cannot be used as well, if "m" is the number of words in the dictionary.

In case two, we should delete several continuous candidate substrings, until we have just collected engough present word. At this time, the index of the deleted candidates cannot be used as final answers.

In case three, we should check if we have already got exactly "m" words or not.

The time complexity is O(n - k), since the "k"-character long substring at any index can only be pushed into and popped from the queue once. Here, this queue is used to maintain the order of the appearance of the valid words.
