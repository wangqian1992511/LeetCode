class Solution {
public:
    bool isValidSerialization(string preorder) {
        s = preorder + ',';
        p = 0;
        bool flag = dfs();
        return (p == s.size()) && flag;
    }
private:
    int p;
    string s;
    
    bool dfs() {
        if (p == s.size())
            return false;
        
        bool isEnd = (s[p] == '#'), ans = true;
        while (s[p] != ',') p++;
        p++;
        
        if (!isEnd)
            ans = dfs() && dfs();
        
        return ans;
    }
};