class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int firstMax = nums[0];
        int secondMax = INT_MIN;
        for(int i = 1; i< nums.size(); i++){
            if(nums[i] >= firstMax){
                secondMax = firstMax;
                firstMax = nums[i];
            }else if(nums[i] > secondMax && nums[i] < firstMax){
                secondMax = nums[i];
            }
        }
        return (firstMax -1) * (secondMax -1);
    }
};