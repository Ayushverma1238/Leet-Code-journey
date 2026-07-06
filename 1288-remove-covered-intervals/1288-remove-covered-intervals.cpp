class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int i =0;
        int n = intervals.size();
        int ans = 1, prevStart = intervals[0][0], prevEnd =intervals[0][1];
        for(int i =1; i< n; i++){
            if(intervals[i][0] > prevStart && intervals[i][1] <= prevEnd){
                continue;
            }
            else if(intervals[i][0] == prevStart){
                prevEnd = max(prevEnd, intervals[i][1]);
            }else{
                ans++;
                prevStart = intervals[i][0];
                prevEnd = intervals[i][1];
            }
        }
        return ans;
    }
};