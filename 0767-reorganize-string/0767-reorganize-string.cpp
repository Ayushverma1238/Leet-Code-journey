class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for (auto c : s) {
            freq[c]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto it : freq) {
            pq.push({it.second, it.first});
        }

        string ans = "";
        while (!pq.empty()) {
            if (pq.size() == 1) {
                if ((ans.size() && ans.back() == pq.top().second) || pq.top().first != 1) {
                    return "";
                } else {
                    ans += pq.top().second;
                    pq.pop();
                }
            } else {
                auto first = pq.top();
                pq.pop();
                auto second = pq.top();
                pq.pop();
                ans += (first.second);
                ans += (second.second);
                first.first--;
                second.first--;
                if (first.first != 0)
                    pq.push(first);
                if (second.first != 0)
                    pq.push(second);
            }
        }

        return ans;
    }
};