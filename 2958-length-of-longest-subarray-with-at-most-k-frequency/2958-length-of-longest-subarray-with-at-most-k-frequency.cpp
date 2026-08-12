class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        unordered_map<int, int> freq;
        int ans = 0;
        while(i <= j && j < n){
            freq[nums[j]]++;
            if(freq[nums[j]] > k){
                freq[nums[i]]--;
                freq[nums[j]]--;
                i++;
            }else{
                ans = max(ans, (j - i +1));
                j++;
            }
        }
        ans = max(ans, (j - i));
        return ans;
    }
};