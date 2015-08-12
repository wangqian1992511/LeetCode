class Trie:
    
    def __init__(self):
        self.d = dict()
        self.s = set()

    # @param {string} word
    # @return {void}
    # Inserts a word into the trie.
    def _insert(self, word, i):
        if i < len(word):
            if word[i] not in self.d:
                self.d[word[i]] = Trie()
            if i == len(word) - 1:
                self.s.add(word[i])
            self.d[word[i]]._insert(word, i + 1)
    
    def insert(self, word):
        self._insert(word, 0)

    # @param {string} word
    # @return {boolean}
    # Returns if the word is in the trie.
    def _search(self, word, i):
        if i < len(word):
            if word[i] not in self.d:
                return False
            if i == len(word) - 1:
                return word[i] in self.s
            return self.d[word[i]]._search(word, i + 1)
        return True
    
    def search(self, word):
        return self._search(word, 0)

    # @param {string} prefix
    # @return {boolean}
    # Returns if there is any word in the trie
    # that starts with the given prefix.
    def _startsWith(self, prefix, i):
        if i < len(prefix):
            if prefix[i] not in self.d:
                return False
            return self.d[prefix[i]]._startsWith(prefix, i + 1)
        return True
            
    def startsWith(self, prefix):
        return self._startsWith(prefix, 0)

# Your Trie object will be instantiated and called as such:
# trie = Trie()
# trie.insert("somestring")
# trie.search("key")