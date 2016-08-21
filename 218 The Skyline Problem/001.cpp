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
        vector<nodeT> data;
        int cnt = 0;
        for (auto it: buildings) {
            data.push_back({it[0], it[2], cnt, true});
            data.push_back({it[1], it[2], cnt, false});
            cnt++;
        }
        vector<bool> isPop (cnt + 1, false);
        sort(data.begin(), data.end(), sortCompT());

        priority_queue<nodeT, vector<nodeT>, heapCompT> heap;
        heap.push({0, 0, cnt + 1, true});
        vector<pair<int, int>> ans;
        int lastH = 0;
        for (auto edge: data) {
            if (edge.isLeft) {
                heap.push(edge);
            }
            else {
                isPop[edge.num] = true;
                while (!heap.empty() && isPop[heap.top().num])
                    heap.pop();
            }
            int nowH = heap.top().y;
            if (nowH != lastH) {
                ans.push_back({edge.x, nowH});
                lastH = nowH;
            }
        }
        return ans;
    }
};
