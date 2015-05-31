class Solution {
public:
    int trap(vector<int> &A) {
        int n = A.size();
        stack<int> height, len;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (height.empty()) {
                height.push(A[i]);
                len.push(1);
            }
            else {
                int midH = height.top();
                int midL = len.top();
                if (A[i] < midH) {
                    height.push(A[i]);
                    len.push(1);
                }
                else if (A[i] == midH) {
                   len.pop();
                   len.push(midL+1);
                }
                else {
                    while (true) {
                        height.pop();
                        len.pop();
                        if (height.empty()) {
                            height.push(A[i]);
                            len.push(1);
                            break;
                        }
                        else {
                            int preH = height.top();
                            int preL = len.top();
                            if (A[i] < preH) {
                                height.push(A[i]);
                                len.push(midL + 1);
                                ans += (A[i] - midH) * midL;
                                break;
                            }
                            else if (A[i] == preH) {
                                len.pop();
                                len.push(preL + midL + 1);
                                ans += (A[i] - midH) * midL;
                                break;
                            }
                            else {
                                len.pop();
                                len.push(preL + midL);
                                ans += (preH - midH) * midL;
                                midH = preH;
                                midL = preL + midL;
                            }
                        }                         
                    }
                }
            }
        }
        return ans;
    }
};
