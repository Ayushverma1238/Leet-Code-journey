class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        // Frequency array to store counts of each difference (max diff is 1e5)
        vector<int> difference(100001, 0);
        int n = nums1.size();
        
        for (int i = 0; i < n; i++) {
            difference[abs(nums1[i] - nums2[i])]++;
        }
        
        long long left = (long long)k1 + k2;
        
        for (int i = 100000; i > 0; i--) {
            if (difference[i] > 0) {
                long long take = min((long long)difference[i], left);
                difference[i] -= take;
                difference[i - 1] += take;
                left -= take;
                
                if (left == 0) break;
            }
        }
        
        long long answer = 0;
        for (int i = 1; i <= 100000; i++) {
            if (difference[i] > 0) {
                answer += (long long)difference[i] * i * i;
            }
        }
        
        return answer;
    }
};