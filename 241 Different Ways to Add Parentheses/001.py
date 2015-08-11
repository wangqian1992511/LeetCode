class Solution:
    # @param {string} input
    # @return {integer[]}
    def diffWaysToCompute(self, input):
        ans, num, op = [], [], []
        def divide(input):
            tmp = 0
            for ch in input:
                if ch.isdigit():
                    tmp = tmp * 10 + ord(ch) - ord('0')
                else:
                    num.append(tmp)
                    op.append(ch)
                    tmp = 0
            num.append(tmp)
        def dfs(ans, st, en):
            if st == en:
                ans.append(num[st])
            else:
                for i in range(st, en):
                    a, b = [], []
                    dfs(a, st, i)
                    dfs(b, i + 1, en)
                    if op[i] == '+':
                        for x in a:
                            for y in b:
                                ans.append(x + y)
                    elif op[i] == '-':
                        for x in a:
                            for y in b:
                                ans.append(x - y)
                    elif op[i] == '*':
                        for x in a:
                            for y in b:
                                ans.append(x * y)  
        divide(input)
        dfs(ans, 0, len(num) - 1)
        return ans