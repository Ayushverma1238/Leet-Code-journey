class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        // int maxNum = nums[0];
        // for(auto n : nums){
        //     maxNum = max(maxNum, n);
        // }
        int arr[32][2] = {0};
        for(auto n : nums){
            bitset<32> bits(n);
            string bit = bits.to_string();
            for(int i = 0; i< 32; i++){
                int b = bit[i]-'0';
                arr[i][b]++;
            }
        }
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i< 2; i++){
            for(int j = 0; j< 32; j++){
                if(arr[j][i] == 0) continue;
                ans += arr[j][i] * (n - arr[j][i]);
            }
        }
        return ans /2;
    }
};

// 2 1 
// 1 2
// 1 2
// 3 0
