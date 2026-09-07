class Solution {
public:
    int minOperations(int k) {
        int ans = INT_MAX;
        // if(k == 1) return 0;
        // if(k <= 3) return k;
        for(int i = 1; i * i <= k; i++){
            int inc = i -1;
            int div = (k + i -1) / i -1;
            ans = min(ans, inc + div );
        }
        return ans;
    }
};