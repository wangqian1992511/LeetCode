class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0;
        int n = words.size();
        int *bit = new int [n];
        int *len = new int [n];
        for (int i = 0; i < n; i++) {
            bit[i] = calcBit(words[i]);
            len[i] = words[i].size();
            for (int j = 0; j < i; j++)
                if (! (bit[i] & bit[j]))
                    ans = max(ans, len[i] * len[j]);
        }
        return ans;
    }
private:
    int calcBit(string str) {
        int ans = 0, n = str.size();
        for (int i = 0; i < n; i++)
            ans |= 1 << (str[i] - 'a');
        return ans;
    }
    
};