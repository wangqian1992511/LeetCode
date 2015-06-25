class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        now = 0;
        mul = false;
        pos = true;
        num.push_back(0);
        sign.push_back(true);

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if ((ch <= '9') && (ch >= '0'))
                now = now * 10 + (ch - '0');
            else if (ch == '*') {
                calcNum();
                mul = true;
                pos = true;
            }
            else if (ch == '/') {
                calcNum();
                mul = true;
                pos = false;
            }
            else if (ch == '+') {
                calcNum();
                mul = false;
                pos = true;
                sign.push_back(true);
            }
            else if (ch == '-') {
                calcNum();
                mul = false;
                pos = false;
                sign.push_back(false);
            }
        }
        calcNum();
        
        int ans = num.front();
        num.pop_front();
        while (!sign.empty()) {
            pos = sign.front();
            sign.pop_front();
            if (pos)
                ans += num.front();
            else
                ans -= num.front();
            num.pop_front();
        }
        return ans;
    }
private:
    bool mul, pos;
    int now, cul;
    deque<int> num;
    deque<bool> sign;    
    void calcNum() {
        if (!mul && pos) 
            num.push_back(now);
        else if (!mul && !pos) 
            num.push_back(now);
        else if (mul && pos) {
            int x = num.back();
            num.pop_back();
            x *= now;
            num.push_back(x);
        }
        else {
            int x = num.back();
            num.pop_back();
            x /= now;
            num.push_back(x);            
        }
        now = 0;
    }
};