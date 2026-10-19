class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        auto it = lower_bound(nums.begin(), nums.end(), target);
        vector<int> ans;
        for(int i = it- nums.begin();i < nums.size(); i++){
            if(nums[i] == target) {
                ans.push_back(i);
            }else
                break;
        }
        return ans;
    }
};