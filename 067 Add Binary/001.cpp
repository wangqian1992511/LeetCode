class Solution {
public:
    string addBinary(string a, string b) {
        int la = a.size();
        int lb = b.size();
        if (la > lb)
            for (int i = 0; i < (la - lb); i++)
                b = '0' + b;
        else 
            for (int i = 0; i < (lb - la); i++)
                a = '0' + a;
        
        int l = la > lb ? la : lb;
        string c = "";
        bool flag = false;
        for (int i = l - 1; i >=0; i--) {
            c = ((a[i] == '1') ^ (b[i] == '1') ^ flag ? '1' : '0') + c;
            flag = ((a[i] == '1') ^ (b[i] == '1')) && flag || (a[i] == '1') && (b[i] == '1');
        }
        if (flag)
            c = '1' + c;
        return c;
    }
};