class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastIdx(26, -1);
        int n = s.size();
        for(int i = 0; i < n; i++){
            lastIdx[s[i] - 'a']= i;
        }
        vector<int> ans;
        int currLast = 0, currStart = 0;
        for(int i = 0; i < n; i++){
            if(currStart == currLast){
                currLast = lastIdx[s[currStart]-'a']; 
                if(currStart == currLast){
                    ans.push_back(1);
                    currStart = currLast = currStart + 1;
                }
                continue;
            }
            if(i == currLast){
                int len= currLast - currStart + 1;
                ans.push_back(len);
                currStart = currLast = i + 1;
            }
            if(i < currLast && currLast < lastIdx[s[i]-'a']){
                currLast = lastIdx[s[i]-'a'];
            }   
        }
        // int len= currLast - currStart + 1;
        // ans.push_back(len);
        return ans;
    }
};