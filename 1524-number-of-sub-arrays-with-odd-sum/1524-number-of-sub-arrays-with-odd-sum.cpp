class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long oddCount = 0, prefSum = 0;
        for(auto n : arr){
            prefSum += n;
            oddCount += prefSum % 2;
        }
        oddCount += (arr.size() - oddCount) * oddCount;
        return oddCount % 1'000'000'007;
    }
};