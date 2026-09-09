class Solution {
public:
    int minCost(int n) {
        int val = n-1;
        return val * (val + 1)/2;
    }
};