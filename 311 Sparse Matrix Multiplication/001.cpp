class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int na = A.size();
        int nb = B.size();
        int ma = A[0].size();
        int mb = B[0].size();
        
        vector<int> *rowA = new vector<int> [ma];
        vector<int> *colB = new vector<int> [nb];
        unordered_set<int> s, t;
        for (int i = 0; i < na; i++)
            for (int j = 0; j < ma; j++)
                if (A[i][j]) {
                    rowA[j].push_back(i);
                    s.emplace(j);
                }
        for (auto i: s) {
            bool flag = false;
            for (int j = 0; j < mb; j++)
                if (B[i][j]) {
                    colB[i].push_back(j);
                    flag = true;
                }
            if (!flag)
                t.emplace(i);
        }
        
        for (auto i: t)
            s.erase(i);
        
        vector<int> tmp (mb, 0);
        vector<vector<int>> ans (na, tmp);
        for (auto k: s)
            for (auto i: rowA[k])
                for (auto j: colB[k])
                    ans[i][j] += A[i][k] * B[k][j];
        
        return ans;
    }
    
};