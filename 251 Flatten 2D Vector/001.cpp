class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        i = 0; 
        j = 0;
        this->vec2d = vec2d;
    }

    int next() {
        j++;
        return vec2d[i][j - 1];
    }

    bool hasNext() {
        while (i < vec2d.size()) 
            if (j == vec2d[i].size()) {
                i++;
                j = 0;
            }
            else
                return true;
        return false;
    }
private:
    int i, j;
    vector<vector<int>> vec2d;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */