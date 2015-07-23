class Solution {
public:
    int compareVersion(string version1, string version2) {
        int p, va, vb;
        while (version1.size() && version2.size()) {
            string sa = getNext(version1);
            string sb = getNext(version2);
            int na = atoi(sa.c_str());
            int nb = atoi(sb.c_str());
            if (na > nb) return 1;
            if (na < nb) return -1;
        }
        if (version1.size()) { 
            string sa = getNext(version1);
            return atoi(sa.c_str()) > 0;
        }
        if (version2.size()) {
            string sb = getNext(version2);
            return -(atoi(sb.c_str()) > 0);
        } 
        return 0;
    }
private:
    string getNext(string &str) {
        size_t idx = str.find('.', 0);
        string ans;
        if (idx == string::npos) {
            ans = str;
            str = "";
        }
        else {
            ans = str.substr(0, idx); 
            str = str.substr(idx + 1);         
        }
        return ans;
    }
};