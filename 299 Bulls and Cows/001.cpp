class Solution {
public:
    string getHint(string secret, string guess) {
        int compRight = 0, halfRight = 0;
        int cnt[256] = {0};
        int n = secret.size();
        for (int i = 0; i < n; i++) {
            cnt[secret[i]]++;
            if (guess[i] == secret[i])
                compRight++;
        }
        for (int i = 0; i < n; i++)
            if (cnt[guess[i]] > 0) {
                cnt[guess[i]]--;
                halfRight++;
            }
        halfRight -= compRight;
        return to_string(compRight) + "A" + to_string(halfRight) + "B";
    }
};
