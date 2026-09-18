#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> first(26, -1), last(26, -1);

        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }

        vector<pair<int, int>> valid_intervals;

        for (int i = 0; i < 26; ++i) {
            if (first[i] == -1) continue;

            int start = first[i];
            int end = last[i];
            bool valid = true;

            for (int j = start; j <= end; ++j) {
                int c = s[j] - 'a';
                if (first[c] < start) {
                    valid = false;
                    break;
                }
                end = max(end, last[c]);
            }

            if (valid) {
                valid_intervals.push_back({end, start}); // store {end, start} for easy sorting
            }
        }

        // Sort intervals by end index
        sort(valid_intervals.begin(), valid_intervals.end());

        vector<string> result;
        int prev_end = -1;

        for (auto& [end, start] : valid_intervals) {
            if (start > prev_end) {
                result.push_back(s.substr(start, end - start + 1));
                prev_end = end;
            }
        }

        return result;
    }
};