struct nodeT {
    int key, pt, idx;
};

struct heapCompT {
  bool operator ()(nodeT &a, nodeT &b) {
      return a.key > b.key;
  }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<nodeT, vector<nodeT>, heapCompT> heap;
        int n = matrix.size();
        for (int i = 0; i < n; i++)
            heap.push({matrix[i][0], i, 0});

        int ans = 0;
        for (int i = 0; i < k; i++) {
            nodeT node = heap.top();
            heap.pop();
            ans = node.key;
            node.idx++;
            if (node.idx < n) {
                node.key = matrix[node.pt][node.idx];
                heap.push(node);
            }
        }
        return ans;
    }
};
