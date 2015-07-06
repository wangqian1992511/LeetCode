struct nodeT {
    int x, y, num;
    bool isLeft;
};

struct heapCompT {
    bool operator()(nodeT &a, nodeT &b) {
        return a.y < b.y;
    }
};

struct sortCompT {
    bool operator()(nodeT &a, nodeT &b) {
        if (a.x != b.x) return a.x < b.x;
        if (a.isLeft ^ b.isLeft) return a.isLeft;
        return a.isLeft ? a.y > b.y : a.y < b.y;
    }
};

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        buildData(buildings);
        sort(data.begin(), data.end(), sortCompT());
        findAns();
        return ans;
    }
private:
    priority_queue<nodeT, vector<nodeT>, heapCompT> heap;
    vector<pair<int, int>> ans;
    vector<nodeT> data;
    vector<bool> isPop;
    int n;
    void buildData(vector<vector<int>>& buildings) {
        n = buildings.size();
        for (int i = 0; i < n; i++) {
            int xa = buildings[i][0];
            int xb = buildings[i][1];
            int y = buildings[i][2];
            data.push_back({xa, y, i, true});
            data.push_back({xb, y, i, false});
            isPop.push_back(false);
        }
        n <<= 1;
    }
    void findAns() {
        int lastH = 0, nowH;
        for (int i = 0; i < n; i++) {
            nodeT edge = data[i];
            if (edge.isLeft) {
                heap.push(edge);
            }
            else {
                isPop[edge.num] = true;
                while (!heap.empty() && isPop[heap.top().num]) 
                    heap.pop();
            }
            nowH = heap.empty() ? 0 : heap.top().y;
            if (nowH != lastH) {
                ans.push_back({edge.x, nowH});
                lastH = nowH;
            }
        }        
    }
};