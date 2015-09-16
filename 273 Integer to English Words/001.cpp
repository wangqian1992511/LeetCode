class Solution {
public:
    string numberToWords(int x) {
        if (!x) return "Zero";
        ans = "";
        string tmp;
        
        t = x % 1000;
        tmp = threeDigitsToWords(t, 0);
        if (tmp.size() && ans.size()) tmp += ' ';
        ans = tmp + ans;   
        x /= 1000;
        if (!x) return ans;
        
        t = x % 1000;
        tmp = threeDigitsToWords(t, 1);
        if (tmp.size() && ans.size()) tmp += ' ';
        ans = tmp + ans;   
        x /= 1000;
        if (!x) return ans;
        
        t = x % 1000;
        tmp = threeDigitsToWords(t, 2);
        if (tmp.size() && ans.size()) tmp += ' ';
        ans = tmp + ans;   
        x /= 1000;
        if (!x) return ans;
        
        t = x % 1000;
        tmp = threeDigitsToWords(t, 3);
        if (tmp.size() && ans.size()) tmp += ' ';
        ans = tmp + ans;   
        return ans;        
    }
private:
    string ans;
    int t;
    string threeDigitsToWords (int x, int f) {
        string ans = "";
        if (x) {
            int t = x / 100;
            if (t) ans += nameDigit(t) + " Hundred";
            x %= 100;
            if (x) {
                if (ans.size()) ans += ' ';
                if (x <= 19) ans += nameDigit(x);
                else {
                    int t = x / 10 * 10;
                    ans += nameDigit(t);
                    x %= 10;
                    if (x) ans += ' ' + nameDigit(x);
                }
            }
            if (f == 1) ans += " Thousand";
            else if (f == 2) ans += " Million";
            else if (f == 3) ans += " Billion";
        }
        return ans;
    }
    string nameDigit(int x) {
        switch (x) {
            case 1: return "One";
            case 2: return "Two";
            case 3: return "Three";
            case 4: return "Four";
            case 5: return "Five";
            case 6: return "Six";
            case 7: return "Seven";
            case 8: return "Eight";
            case 9: return "Nine";
            case 10: return "Ten";
            case 11: return "Eleven";
            case 12: return "Twelve";
            case 13: return "Thirteen";
            case 14: return "Fourteen";
            case 15: return "Fifteen";
            case 16: return "Sixteen";
            case 17: return "Seventeen";
            case 18: return "Eighteen";
            case 19: return "Nineteen";
            case 20: return "Twenty";
            case 30: return "Thirty";
            case 40: return "Forty";
            case 50: return "Fifty";
            case 60: return "Sixty";
            case 70: return "Seventy";
            case 80: return "Eighty";
            case 90: return "Ninety";
            default: return "";
        }
    }
};