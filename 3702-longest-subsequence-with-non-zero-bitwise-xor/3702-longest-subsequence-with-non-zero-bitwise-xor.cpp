class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int zero = 0;
        int n = nums.size();
        int ans = 0;
        for(auto c : nums){
            ans ^= c;
            if(c == 0)
                zero++;
        }
        return (ans != 0) ? n : (zero == n ? 0 : n -1 ); 
    }
};