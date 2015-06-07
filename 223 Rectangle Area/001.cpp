struct rect {
    int xa, ya, xb, yb;
};

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        rect rA = {A, B, C, D};
        rect rB = {E, F, G, H};
        list.push_back(rA);
        list.push_back(rB);
        
        int ans = 0;
        int n = list.size();
        for (int i = 0; i < n; i++)
            ans += cut(list[i].xa, list[i].ya, list[i].xb, list[i].yb, i - 1);
        return ans;
    }
private:
    vector<rect> list;
    int cut(int xa, int ya, int xb, int yb, int q) {
        if (q < 0)
            return calcS(xa, ya, xb, yb);
        if (uncover(xa, ya, xb, yb, q))
            return cut(xa, ya, xb, yb, q - 1);
        int ans = 0;
        if (list[q].xa > xa) {
            ans += cut(xa, ya, list[q].xa, yb, q - 1);
            xa = list[q].xa;
        }
        if (list[q].xb < xb) {
            ans += cut(list[q].xb, ya, xb, yb, q - 1);
            xb = list[q].xb;
        }
        if (list[q].ya > ya) {
            ans += cut(xa, ya, xb, list[q].ya, q - 1);
            ya = list[q].ya;
        }
        if (list[q].yb < yb) {
            ans += cut(xa, list[q].yb, xb, yb, q - 1);
            yb = list[q].yb;
        }
        return ans;
        
    }
    int calcS(int xa, int ya, int xb, int yb) {
        return (xb - xa) * (yb - ya);
    }
    bool uncover(int xa, int ya, int xb, int yb, int q) {
        if (list[q].xa >= xb) return true;
        if (list[q].xb <= xa) return true;
        if (list[q].ya >= yb) return true;
        if (list[q].yb <= ya) return true;
        return false;
    }
};
