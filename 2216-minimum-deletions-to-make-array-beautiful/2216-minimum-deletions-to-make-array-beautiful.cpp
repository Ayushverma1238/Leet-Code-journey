class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)return 0;
        if(n == 1) return 1;
        int i =0;
        int del = 0;
        while(i < n-1){
            if((i - del) % 2 == 0){
                if(nums[i] == nums[i+1]){
                    del++;
                    i++;
                }else{
                    i+=2;
                }
            }else{
                i++;
            }
        }
        return ((n-del) % 2 == 0)? del : del + 1;
    }
};