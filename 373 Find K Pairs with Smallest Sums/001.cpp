struct nodeT {
    int idx1, idx2, key;
};

struct heapCompT {
    bool operator()(nodeT &a, nodeT &b) {
        return a.key > b.key;
    }
};

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> ans;
        int n = nums1.size(), m = nums2.size();
        if (!n || !m) return ans;
        k = min(n * m, k);

        priority_queue<nodeT, vector<nodeT>, heapCompT> heap;
        for (int i = 0; i < n; i++)
            heap.push({i, 0, nums1[i] + nums2[0]});

        for (int i = 0; i < k; i++) {
            nodeT node = heap.top();
            heap.pop();
            ans.push_back({nums1[node.idx1], nums2[node.idx2]});
            node.idx2++;
            if (node.idx2 < m) {
                node.key = nums1[node.idx1] + nums2[node.idx2];
                heap.push(node);
            }
        }

        return ans;
    }
};
