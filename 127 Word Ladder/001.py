class Solution:
    # @param {string} beginWord
    # @param {string} endWord
    # @param {set<string>} wordDict
    # @return {integer}
    def ladderLength(self, beginWord, endWord, wordDict):
        newQ = [beginWord]
        oldQ = []
        if beginWord in wordDict:
            wordDict.remove(beginWord)
        if endWord not in wordDict:
            wordDict.add(endWord)
        ans = 1
        while len(newQ) > 0 and endWord not in newQ:
            oldQ = newQ
            newQ = []
            while len(oldQ) > 0:
                x = oldQ.pop()
                for i in range(len(x)):
                    for ch in "qwertyuioplkjhgfdsazxcvbnm":
                        t = x[ : i] + ch + x [i + 1 : ]
                        if t in wordDict and ch != x[i]:
                            newQ.append(t)
                            wordDict.remove(t)
            ans += 1
        return ans if endWord in newQ else 0