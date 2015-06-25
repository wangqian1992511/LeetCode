class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        now = "";
        for (int i = 0; i < n; i++)
            if (path[i] == '/') 
                update();
            else
                now += path[i];
        update();
        
        n = s.size();
        if (!n) now = "/";
        for (int i = 0; i < n; i++) {
            now = '/' + s.top() + now;
            s.pop();
        }
        return now;
    }
private:
    string now;
    stack<string> s;
    void update() {
        if ((now == "..") && (!s.empty()))
            s.pop();
        else if ((now != "") && (now != ".") && (now != ".."))
            s.push(now);
        now = "";
    }
};