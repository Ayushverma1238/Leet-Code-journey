class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int ans= 0;
        for(auto n : nums){
            if(n < 10){
                ans += n;
            }else{
                int x = n;
                int newN = 0;
                int maxDig = INT_MIN;
                while(x != 0){
                    int dig = x % 10;
                    maxDig = max(maxDig, dig);
                    newN = newN * 10 + 1;
                    x/= 10;
                }
                ans += (newN * maxDig);
            }
        }
        return ans;
    }
};