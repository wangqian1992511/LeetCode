class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> ans;
        auto it = words.begin();
        auto en = words.end();

        while (it != en) {
            vector<string> line;
            int c = it->size();
            line.push_back(*it++);

            while ((it != en) && (c + 1 + it->size() <= maxWidth)) {
                c += 1 + it->size();
                line.push_back(' ' + *it++);
            }

            int n = line.size();
            if ((it == en) || (n == 1))
                line[n - 1] = line[n - 1] + string(maxWidth - c, ' ');
            else {
                int t = (maxWidth - c) % (n - 1);
                int k = (maxWidth - c) / (n - 1);
                for (int i = 1; i <= t; i++)
                    line[i] = string(k + 1, ' ') + line[i];
                for (int i = t + 1; i < n; i++)
                    line[i] = string(k, ' ') + line[i];
            }

            string str = "";
            for (auto it: line)
                str += it;
            ans.push_back(str);
        }

        return ans;
    }
};
