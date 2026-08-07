#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // Structure to track needed prime factors (2, 3, 5, 7)
    struct Factor {
        int c2 = 0, c3 = 0, c5 = 0, c7 = 0;

        void add_digit(int d) {
            if (d == 2) c2++;
            else if (d == 3) c3++;
            else if (d == 4) c2 += 2;
            else if (d == 5) c5++;
            else if (d == 6) { c2++; c3++; }
            else if (d == 7) c7++;
            else if (d == 8) c2 += 3;
            else if (d == 9) c3 += 2;
        }

        void remove_digit(int d) {
            if (d == 2) c2--;
            else if (d == 3) c3--;
            else if (d == 4) c2 -= 2;
            else if (d == 5) c5--;
            else if (d == 6) { c2--; c3--; }
            else if (d == 7) c7--;
            else if (d == 8) c2 -= 3;
            else if (d == 9) c3 -= 2;
        }

        // Returns minimal string of digits (using 2-9) needed to satisfy remaining factors
        string get_min_digits() const {
            int t2 = max(0, c2), t3 = max(0, c3), t5 = max(0, c5), t7 = max(0, c7);
            string res = "";

            // Greedily consume factors into largest single digits to minimize string length
            while (t2 >= 3) { res += '8'; t2 -= 3; }
            while (t3 >= 2) { res += '9'; t3 -= 2; }
            if (t2 == 2 && t3 == 1) { res += '6'; t2 -= 1; t3 -= 1; }
            while (t2 >= 2) { res += '4'; t2 -= 2; }
            if (t2 == 1 && t3 == 1) { res += '6'; t2 -= 1; t3 -= 1; }
            while (t3 >= 1) { res += '3'; t3 -= 1; }
            while (t2 >= 1) { res += '2'; t2 -= 1; }
            while (t5 >= 1) { res += '5'; t5 -= 1; }
            while (t7 >= 1) { res += '7'; t7 -= 1; }

            sort(res.begin(), res.end());
            return res;
        }
    };

public:
    string smallestNumber(string num, long long t) {
        Factor req;
        long long temp_t = t;

        // Extract prime factors 2, 3, 5, 7
        while (temp_t % 2 == 0) { req.c2++; temp_t /= 2; }
        while (temp_t % 3 == 0) { req.c3++; temp_t /= 3; }
        while (temp_t % 5 == 0) { req.c5++; temp_t /= 5; }
        while (temp_t % 7 == 0) { req.c7++; temp_t /= 7; }

        // If t has prime factors > 7, it's impossible
        if (temp_t > 1) return "-1";

        int n = num.size();
        Factor cur = req;

        // Try matching prefix of num
        int first_zero = -1;
        for (int i = 0; i < n; ++i) {
            if (num[i] == '0') {
                first_zero = i;
                break;
            }
            cur.remove_digit(num[i] - '0');
        }

        // Check if current prefix works
        if (first_zero == -1) {
            string min_suffix = cur.get_min_digits();
            if (min_suffix.empty()) return num; // num already satisfies condition
        }

        // Backtrack to find smallest suffix modification
        int limit = (first_zero != -1) ? first_zero : n - 1;
        
        // Re-align `cur` state to position `limit`
        cur = req;
        for (int i = 0; i < limit; ++i) {
            cur.remove_digit(num[i] - '0');
        }

        for (int i = limit; i >= 0; --i) {
            int start_digit = (num[i] - '0') + 1;
            
            for (int d = start_digit; d <= 9; ++d) {
                Factor next_cur = cur;
                next_cur.remove_digit(d);
                string min_suffix = next_cur.get_min_digits();
                
                int rem_len = n - 1 - i;
                if ((int)min_suffix.size() <= rem_len) {
                    // Valid prefix found! Build the complete string
                    string ans = num.substr(0, i);
                    ans += to_string(d);
                    
                    int ones_needed = rem_len - min_suffix.size();
                    ans.append(ones_needed, '1');
                    ans += min_suffix;
                    return ans;
                }
            }
            
            if (i > 0) {
                cur.add_digit(num[i - 1] - '0'); // Step back
            }
        }

        // If no solution with length `n`, we must increase length to `n + 1` (or more)
        string min_suffix = req.get_min_digits();
        int target_len = max(n + 1, (int)min_suffix.size());
        string ans = "";
        ans.append(target_len - min_suffix.size(), '1');
        ans += min_suffix;

        return ans;
    }
};