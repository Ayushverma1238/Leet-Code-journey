class Solution {
public:

    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();
        int m = to_string(nums[0]).size();
        vector<vector<int>> freq(m, vector<int>(10, 0));
        for(int i = 0; i < n; i++){
            int x = nums[i];
            int j = m-1;
            while(x != 0){
                int rem = x % 10;
                freq[j--][rem]++;
                x /= 10;
            }
        }
        long long ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < 10; j++){
                if(freq[i][j] == 0) continue;
                ans += (1LL * freq[i][j] * (n - freq[i][j]));
            }
        }
        return ans/2;
    }
};