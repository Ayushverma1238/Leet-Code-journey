class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int xorArr2 = 0;

        for(auto num: arr2){
            xorArr2 ^= num;
        }
        int ans = 0;
        for(auto num: arr1){
            ans ^= (num & xorArr2);
        }

        return ans;
    }
};