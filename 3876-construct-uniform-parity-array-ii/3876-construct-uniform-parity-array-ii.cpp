class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minElem = nums1[0];
        for(auto n : nums1){
            minElem = min(minElem, n);
        }
        if(minElem % 2 != 0) return true;
        for(auto n : nums1){
            if(n % 2 != 0){
                return false;
            }
        }
        return true;
    }
};