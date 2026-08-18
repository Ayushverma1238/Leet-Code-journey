class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if(k== 1){
            unordered_map<int,int> mp;
            for(auto n : nums){
                mp[n]++;
            }
            int ans = -1;
            for(auto it : mp){
                if(it.second== 1){
                    ans = max(ans, it.first);
                }
            }
            return ans;
        }
        int m = nums.size();
        if(k == m){
            return *max_element(nums.begin(), nums.end());
        }   

        int left = 0, right = 0;
        

        for(auto n : nums){
            if(n == nums[0])
                left++;
            if(n == nums[m-1])
                right++;
        }
        if(left > 1 && right > 1)
            return -1;
        else if(left == right)
            return max(nums[0], nums[m-1]);
        return (left == 1) ? nums[0] : nums[m-1];
    }
};