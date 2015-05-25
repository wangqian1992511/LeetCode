class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int n = matrix.size();
        if (!n) return;
        int m = matrix[0].size();
        if (!m) return;
        
        bool isRowZero = false, isColZero = false;
        
        for (int j = 0; j < m; j++)
            if (!matrix[0][j])
                isRowZero = true;
                
        for (int i = 0; i < n; i++)
            if (!matrix[i][0])
                isColZero = true;
       
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                if (!matrix[i][j])
                    matrix[0][j] = matrix[i][0] = 0;      
                    
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                if (!matrix[0][j] || !matrix[i][0])
                    matrix[i][j] = 0;
                    
        if (isRowZero)
            for (int j = 0; j < m; j++)
                matrix[0][j] = 0;
        
        if (isColZero)
            for (int i = 0; i < n; i++)
                matrix[i][0] = 0;
    }
};
