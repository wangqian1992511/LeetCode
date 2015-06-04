class Solution {
public:
    int totalNQueens(int n) {
        ans = 0;
        dfs(1, n, ( 1 << n ) - 1, ( 1 << n ) - 1, ( 1 << n ) - 1);
        return ans;
    }
private:
    int ans;
    inline int lowbit(int x) {
    	return x & -x;
    }
    
    void dfs(int i, int n, int verbit, int leftbit, int rightbit)
    {
    	if (i > n) {
    		ans++;
    		return;
    	}
    	
    	int k, tmp = verbit & leftbit & rightbit;
    	while (tmp != 0) {
    		k = lowbit(tmp);
    		tmp -= k;
    		
    		verbit -= k;
    		leftbit -= k;
    		rightbit -= k;
    		
    		dfs(i + 1, n, verbit, (leftbit << 1) + 1, (rightbit >> 1) + (1 << (n-1)));
    		
    		verbit += k;
    		leftbit += k;
    		rightbit += k;
    	}
    }    
};