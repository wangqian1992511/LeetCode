class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int p = 0, q = numbers.size() - 1;
        while (true) {
            while (numbers[p] + numbers[q] < target) p++;
            while (numbers[p] + numbers[q] > target) q--;
            if (numbers[p] + numbers[q] == target) 
                return {p + 1, q + 1};
        }
    }
};