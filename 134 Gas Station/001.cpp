class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        if (!n) return -1;
        int *net = new int [n << 1];
        for (int i = 0; i < n; i++)
            net[i] = net[i+n] = gas[i] - cost[i];
        int p = 0, q = 0, tot = 0;
        while ((q != p + n) && (p < n)) {
            while ((q != p + n) && (tot >= 0))
                tot += net[q++];
            if (tot >= 0) 
                return p;
            while ((tot < 0) && (p != q)) 
                tot -= net[p++];
        }
        return -1;
    }
};