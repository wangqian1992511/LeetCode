class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int *first = new int [numCourses + 1];
        int *deg = new int [numCourses];
        fill(first, first + numCourses, INT_MAX);
        fill(deg, deg + numCourses, 0);
        
        sort(prerequisites.begin(), prerequisites.end());
        int nEdge = prerequisites.size();
        first[numCourses] = nEdge;
        for (int i = nEdge - 1; i >= 0; i--) {
            first[prerequisites[i][0]] = i; 
            deg[prerequisites[i][1]]++;
        }
        
        queue<int> zero;
        for (int i = numCourses - 1; i >= 0; i--) {
            if (first[i] > first[i + 1])
                first[i] = first[i + 1];
            if (!deg[i])
                zero.push(i);
        }
        
        int d = 0; 
        while (!zero.empty()) {
            int i = zero.front();
            zero.pop();
            d++;
            for (int j = first[i]; j < first[i+1]; j++)
                if (! --deg[prerequisites[j][1]])
                    zero.push(prerequisites[j][1]);
        }
        return d == numCourses;
    }
};