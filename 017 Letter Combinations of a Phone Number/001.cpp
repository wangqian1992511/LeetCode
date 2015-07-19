class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (n = digits.size()) 
            dfs(digits, 0, "");
        return ans;
    }
private:
    int n;
    vector<string> ans;
    void dfs(string &digits, int d, string now) {
        if (d == n) 
            ans.push_back(now);
        else {
            string str = "";
            if (digits[d] == '2')
                str = "abc";
            else if (digits[d] == '3')
                str = "def";
            else if (digits[d] == '4')
                str = "ghi";
            else if (digits[d] == '5')
                str = "jkl";
            else if (digits[d] == '6')
                str = "mno";
            else if (digits[d] == '7')
                str = "pqrs";
            else if (digits[d] == '8')
                str = "tuv";
            else if (digits[d] == '9')
                str = "wxyz";
            int l = str.size();
            for (int i = 0; i < l; i++)
                dfs(digits, d + 1, now + str[i]);
        }
    }
};