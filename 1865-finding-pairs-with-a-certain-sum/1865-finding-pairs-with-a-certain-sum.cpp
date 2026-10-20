class FindSumPairs {
    unordered_map<int, int> mp2;
    unordered_map<int, int> countVal;
    vector<int> nums;
    int n;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(int i =0; i < nums2.size(); i++){
            mp2[i] = nums2[i];
            countVal[nums2[i]]++;
        }
        nums = {nums1.begin(), nums1.end()};
        n = nums1.size();
    }
    
    void add(int index, int val) {
        int currVal = mp2[index];
        countVal[currVal]--;
        if(countVal[currVal] == 0)
            countVal.erase(currVal);
        mp2[index] += val;
        countVal[mp2[index]]++;
    }
    
    int count(int tot) {
        int ans= 0;
        for(int i = 0; i < n; i++){
            int diff = tot - nums[i];
            if(countVal.count(diff)){
                ans += countVal[diff];
            }
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */