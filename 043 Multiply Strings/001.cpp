class Solution {
public:
    string multiply(string num1, string num2) {
        int n = max(num1.size(), num2.size());
        int *a = convert(num1, n);
        int *b = convert(num2, n);
        int *c = mul(a, b, n);
        return generate(c, n);
    }
private:
    int* convert(string num, int n) {
        int *a = new int [n];
        fill(a, a + n, 0);
		n = num.size();
        for (int i = 0; i < n; i++)
            a[i] = (num[n-1-i] - '0');
        return a;
    }
    int* mul(int *a, int *b, int n) {
        int *c = new int [(n << 1) + 1];
        fill(c, c + (n << 1) + 1, 0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
				int t = c[i+j] + a[i] * b[j];
                c[i+j] = t % 10;
                c[i+j+1] += t / 10;
            }
        return c;
    }
    string generate(int *c, int n) {
        string ans = "";
        int i = (n << 1);
        while (!c[i] && (i > 0)) 
            i--;
        while (i >= 0) 
            ans += char(c[i--] + '0');
        return ans;
    }
};