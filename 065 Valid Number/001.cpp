class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        int state = 1;
        int i = 0; 
        while ((i < n) && (s[i] == ' ')) 
            i++;
        while ((n > 0) && (s[n-1] == ' ')) 
            n--;
        for (; i < n; i++) {
            state = update(state, s[i]);
            if (state == -1)
                break;
        }
        return (state == 3) || (state == 5) || (state == 8);
    }
private:
    int update(int state, char ch) {
        switch (state) {
            case 1:
                if ((ch == '-') || (ch == '+')) return 2;
                if ((ch >= '0') && (ch <= '9')) return 3;
                if (ch == '.') return 4;
                return -1;
            case 2:
                if ((ch >= '0') && (ch <= '9')) return 3;
                if (ch == '.') return 4;
                return -1;
            case 3:
                if ((ch >= '0') && (ch <= '9')) return 3;
                if (ch == '.') return 5;
                if ((ch == 'e') || (ch == 'E')) return 6;
                return -1;
            case 4:
                if ((ch >= '0') && (ch <= '9')) return 5;
                return -1;
            case 5:
                if ((ch >= '0') && (ch <= '9')) return 5;
                if ((ch == 'e') || (ch == 'E')) return 6;
                return -1;
            case 6:
                if ((ch == '-') || (ch == '+')) return 7;
                if ((ch >= '0') && (ch <= '9')) return 8;
                return -1;
            case 7:
                if ((ch >= '0') && (ch <= '9')) return 8;
                return -1;
            case 8:
                if ((ch >= '0') && (ch <= '9')) return 8;
                return -1;
        }
    }
};