class Solution {
public:
    string countAndSay(int n) {
        string now = "1";
        for (int i = 2; i <= n; i++) {
            string tmp = "";
            int l = now.size(), cnt = 0;
            char ch = now[0];
            for (int j = 0 ; j < l; j++) 
                if (now[j] != ch) {
                    tmp += itoa(cnt);
                    tmp += ch;
                    cnt = 1;
                    ch = now[j];
                }
                else 
                    cnt++;
            tmp += itoa(cnt);
            tmp += ch;
            now = tmp;
        }
        return now;
    }
private:
    string itoa(int x) {
        string str = "";
        while (x > 0) {
            str = char('0' + (x % 10)) + str;
            x /= 10;
        }
        return str;
    }
};