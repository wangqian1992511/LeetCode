class Solution {
public:
    bool isStrobogrammatic(string num) {
        int n = num.size();
        for (int i = 0; i < n; i++)
            switch (num[i]) {
                case '0': 
                case '1': 
                case '8': if (num[n-1-i] != num[i]) return false;
                        break;
                case '6': if (num[n-1-i] != '9') return false;
                        break;
                case '9': if (num[n-1-i] != '6') return false;
                        break;
                default: return false;
            }
        return true;
    }
};