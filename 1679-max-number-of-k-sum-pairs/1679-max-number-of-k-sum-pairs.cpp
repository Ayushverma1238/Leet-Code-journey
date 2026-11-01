class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int i = 0, j = nums.size()-1;
        while(i < j){
            int sum = nums[i] + nums[j];
            if(sum == k){
                ans++;
            }
            if(sum > k){
                j--;
            }else if(sum < k){
                i++;
                
            }else{
                i++;
                j--;
            }
        }
        return ans;
    }
};