001.cpp (52ms):

This is my first experience on Trie. Obviously, this problem can be solved with unordered_map, but maybe it's better to purely practice designing the data structure.

The Trie is implemented with "left son right sibling", since this is not a binary tree. When we'd like to insert a string, we can first append an ending char "@" to it. This will make the whole implementation easier, because we do not need to care searching a prefix to fail the test or meeting an empty node any more. Due to this feature, the initial Trie is a single node with character "@". Hence, when performing the first insertion or the first searching, we can avoid an empty tree.

The Trie has different layers. The i-th layer corresponds to the i-th char in a string. Thus, we can deal with the string char by char, which means checking the Trie layer by layer. We can implement the function of searching first, because it is easier. Then we should modify the failing searching part to implement insertion. The time complexity is O(m), where "m" is length of longest string. The memory complexity is O(nm), where "n" is the number of strings.
