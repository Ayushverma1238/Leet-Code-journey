#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int max_val = *max_element(nums.begin(), nums.end());
        
        // Step 1: Count frequency of each number
        vector<long long> freq(max_val + 1, 0);
        for (int num : nums) {
            freq[num]++;
        }
        
        // Step 2: For each i, count how many elements in nums are multiples of i
        vector<long long> gcd_count(max_val + 1, 0);
        for (int i = max_val; i >= 1; --i) {
            long long multiples = 0;
            for (int j = i; j <= max_val; j += i) {
                multiples += freq[j];
            }
            
            // Total pairs formed by these multiples
            long long total_pairs = multiples * (multiples - 1) / 2;
            
            // Subtract the pairs that have a strictly larger GCD (multiples of i)
            for (int j = 2 * i; j <= max_val; j += i) {
                total_pairs -= gcd_count[j];
            }
            gcd_count[i] = total_pairs;
        }
        
        // Step 3: Create a prefix sum array of the GCD pair counts
        vector<long long> prefix_sums(max_val + 1, 0);
        for (int i = 1; i <= max_val; ++i) {
            prefix_sums[i] = prefix_sums[i - 1] + gcd_count[i];
        }
        
        // Step 4: Answer each query using binary search (upper_bound)
        vector<int> ans;
        ans.reserve(queries.size());
        for (long long q : queries) {
            // Find the first GCD value where cumulative pairs strictly exceed query index q
            auto it = upper_bound(prefix_sums.begin(), prefix_sums.end(), q);
            ans.push_back(distance(prefix_sums.begin(), it));
        }
        
        return ans;
    }
};