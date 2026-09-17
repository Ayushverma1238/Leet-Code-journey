class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> best(n, INT_MAX / 2); // Stores min length seen so far up to index i
        
        int left = 0, sum = 0;
        int ans = INT_MAX / 2;
        int min_len = INT_MAX / 2;
        
        for (int right = 0; right < n; ++right) {
            sum += arr[right];
            
            // Shrink window if sum exceeds target
            while (sum > target) {
                sum -= arr[left++];
            }
            
            if (sum == target) {
                int curr_len = right - left + 1;
                
                // If there's a valid non-overlapping subarray before 'left'
                if (left > 0 && best[left - 1] != INT_MAX / 2) {
                    ans = min(ans, curr_len + best[left - 1]);
                }
                
                min_len = min(min_len, curr_len);
            }
            
            // best[right] is the shortest valid subarray seen up to index 'right'
            best[right] = min(right > 0 ? best[right - 1] : INT_MAX / 2, min_len);
        }
        
        return ans >= INT_MAX / 2 ? -1 : ans;
    }
};