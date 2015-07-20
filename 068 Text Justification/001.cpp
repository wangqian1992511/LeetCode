class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> ans;
        int n = words.size();
        int q = 0;
        while (q < n) {
            vector<string> line;
            int c = words[q].size();
            line.push_back(words[q++]);
            
            while ((q < n) && (c + 1 + words[q].size() <= L)) {
                c += 1 + words[q].size();
                line.push_back(' ' + words[q++]);
            }

            int m = line.size();
            if ((q == n) || (m == 1)) {
                while (c != L) {
                    line[m-1] = line[m-1] + ' ';
                    c++;
                }
            }
            else {
                while (c != L) {
                    for (int i = 1; (i < m) && (c != L); i++) {
                        line[i] = ' ' + line[i];
                        c++;
                    }
                }
            }
            
            string str = "";
            for (int i = 0; i < m; i++)
                str += line[i];
            ans.push_back(str);            
        }
        return ans;
    }
};