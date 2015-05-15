class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        int n = strs.size();
        if (n <= 1) return {};
        vector<string> newS;
        for (int i = 0; i < n; i++) {
            string tmp = strs[i];
            qSort(tmp, 0, tmp.size() - 1);
            newS.push_back(tmp);
        }
        qSort2(newS, strs, 0, n-1);
        vector<string> ans;
        int p = 0;
        while (p < n - 1) {
            while ((p < n-1) && (newS[p] != newS[p+1]))
                p++;
            if (p == n-1)
                break;
            do 
                ans.push_back(strs[p++]);
            while ((p < n) && (newS[p] == newS[p-1]));
        }
        return ans;
    }
private:
    void qSort(string &a, int st, int en) {
        if (st >= en) return;
        int l = st, r = en;
        char key = a[(l + r) >> 1];
        while (l < r) {
            while (a[l] < key) l++;
            while (a[r] > key) r--;
            if (l <= r) {
                char ch = a[l];
                a[l++] = a[r];
                a[r--] = ch;
            }
        }
        qSort(a, st, r);
        qSort(a, l, en);
    }
    void qSort2(vector<string> &newS, vector<string> &strs, int st, int en) {
        if (st >= en) return;
        int l = st, r = en;
        string key = newS[(l + r) >> 1];
        while (l < r) {
            while (newS[l] < key) l++;
            while (newS[r] > key) r--;
            if (l <= r) {
                swap(newS[l], newS[r]);
                swap(strs[l], strs[r]);
                l++;
                r--;
            }
        }
        qSort2(newS, strs, st, r);
        qSort2(newS, strs, l ,en);
    }
};