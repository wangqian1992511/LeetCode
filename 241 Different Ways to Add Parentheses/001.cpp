class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        divide(input);
        dfs(ans, 0, n-1);
        return ans;
    }
private:
    int n;
    vector<int> num, ans;
    vector<char> op;
    void divide(string input) {
        int tmp = 0, len = input.size();
        for (int i = 0; i < len; i++) 
            if (('0' <= input[i]) && (input[i] <= '9'))
                tmp = tmp * 10 + (input[i] - '0');
            else {
                num.push_back(tmp);
                tmp = 0;
                op.push_back(input[i]);
            }
        num.push_back(tmp);
        n = num.size();
    }
    void dfs(vector<int> &ans, int st, int en) {
        if (st == en) 
            ans.push_back(num[st]);
        else
            for (int i = st; i < en; i++) {
                vector<int> a, b;
                dfs(a, st, i);
                dfs(b, i + 1, en);
                int sa = a.size(), sb = b.size();
                if (op[i] == '+')
                    for (int j = 0; j < sa; j++)
                        for (int k = 0; k < sb; k++)
                            ans.push_back(a[j] + b[k]);
                else if (op[i] == '-')
                    for (int j = 0; j < sa; j++)
                        for (int k = 0; k < sb; k++)
                            ans.push_back(a[j] - b[k]);
                else if (op[i] == '*')
                    for (int j = 0; j < sa; j++)
                        for (int k = 0; k < sb; k++)
                            ans.push_back(a[j] * b[k]);        
            }
    }
};