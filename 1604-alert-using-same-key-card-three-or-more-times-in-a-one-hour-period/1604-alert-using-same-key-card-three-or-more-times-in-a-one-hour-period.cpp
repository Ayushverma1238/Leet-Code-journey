class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<int>> workerTimes;
        
        int n = keyName.size();
        for (int i = 0; i < n; ++i) {
            string name = keyName[i];
            string timeStr = keyTime[i];
            
            int hours = stoi(timeStr.substr(0, 2));
            int minutes = stoi(timeStr.substr(3, 2));
            int totalMinutes = hours * 60 + minutes;
            
            workerTimes[name].push_back(totalMinutes);
        }
        
        vector<string> result;
        
        for (auto& pair : workerTimes) {
            const string& name = pair.first;
            vector<int>& times = pair.second;
            
            sort(times.begin(), times.end());
            
            bool alerted = false;
            for (int i = 0; i + 2 < times.size(); ++i) {
                // Check if the 1st and 3rd swipe are within 60 minutes
                if (times[i + 2] - times[i] <= 60) {
                    alerted = true;
                    break;
                }
            }
            
            if (alerted) {
                result.push_back(name);
            }
        }
        
        sort(result.begin(), result.end());
        
        return result;
    }
};