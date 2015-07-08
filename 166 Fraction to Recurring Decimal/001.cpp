class Solution {
public:
    string fractionToDecimal(int64_t numerator, int64_t denominator) {
        if (numerator == 0)
            return "0";
        
        bool neg = (numerator < 0) ^ (denominator < 0);
        if (numerator < 0)
            numerator = -numerator;
        if (denominator < 0)
            denominator = -denominator;
        
        int64_t g = gcd(numerator, denominator);
        int64_t a = numerator / g;
        int64_t b = denominator / g;
        int64_t c = a / b;
        a %= b;
        
        string ans = "";
        if (neg) 
            ans = "-";
        ans += itoa(c);
        if (a) {
            int64_t n = getCnt(b);
            ans += '.';
            for (int i = 0; i < n; i++) {
                a *= 10;
                ans += '0' + (a / b);
                a %= b;
            }
        }
        if (a) {
            ans += '(';
            g = gcd(a, b);
            a /= g;
            b /= g;
			unordered_set<int64_t> s;
			while (s.find(a) == s.end()) {
                s.emplace(a);
				a *= 10;
                ans += '0' + (a / b);
                a %= b;
			}
            ans += ')';
        }
        return ans;
    }
private:
    int64_t gcd(int64_t a, int64_t b) {
        if (!b)
            return a;
        else
            return gcd(b, a % b);
    }
    string itoa(int64_t x) {
        if (!x)
            return "0";
        else {
            string str = "";
            while (x) {
                char c = '0' + (x % 10);
                x /= 10;
                str = c + str;
            }
            return str;
        }
    }
    int64_t getCnt(int64_t x) {
        int64_t a = getCntD(x, 2);
        int64_t b = getCntD(x, 5);
        return a > b ? a : b;
    }
    int64_t getCntD(int64_t x, int64_t d) {
        int64_t c = 0;
        while (!(x % d)) {
            x /= d;
            c++;
        }
        return c;
    }
};