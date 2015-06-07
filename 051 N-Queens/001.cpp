class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        for (int i = 0; i < n; i++) log[1 << i] = i;
        dfs(1, n, ( 1 << n ) - 1, ( 1 << n ) - 1, ( 1 << n ) - 1);
        return ans;
    }
private:
    vector<vector<string>> ans;
    vector<string> now;
    unordered_map<int, int> log;

    inline int lowbit(int x) {
    	return x & -x;
    }
    
    void dfs(int i, int n, int verbit, int leftbit, int rightbit) {
    	if (i > n) {
    		ans.push_back(now);
    		return;
    	}
    	
    	int k, tmp = verbit & leftbit & rightbit;
    	while (tmp != 0) {
    		k = lowbit(tmp);
    		tmp -= k;
    	    string line (n, '.');
    	    line[log[k]] = 'Q';
    		
    		verbit -= k;
    		leftbit -= k;
    		rightbit -= k;
    		now.push_back(line);
    		
    		dfs(i + 1, n, verbit, (leftbit << 1) + 1, (rightbit >> 1) + (1 << (n-1)));
    		
    		now.pop_back();
    		verbit += k;
    		leftbit += k;
    		rightbit += k;
    	}
    } 
};