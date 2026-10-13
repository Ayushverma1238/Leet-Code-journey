class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for (const string& t : timePoints) {
            int h = stoi(t.substr(0, 2));
            int m = stoi(t.substr(3, 2));
            minutes.push_back(h * 60 + m);
        }
        
        // Sort the minutes
        sort(minutes.begin(), minutes.end());
        
        int minDiff = INT_MAX;
        
        for (size_t i = 1; i < minutes.size(); ++i) {
            minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
        }
        
        int wrapAroundDiff = (1440 - minutes.back()) + minutes[0];
        minDiff = min(minDiff, wrapAroundDiff);
        
        return minDiff;
    }
};