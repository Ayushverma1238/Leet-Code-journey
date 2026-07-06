class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, int> freq;
        for (int x : arr)
            freq[x]++;

        vector<int> bucket(n + 1, 0);

        for (auto &[_, f] : freq)
            bucket[f]++;

        int removed = 0;
        int ans = 0;
        int target = n / 2;

        for (int f = n; f >= 1 && removed < target; f--) {
            while (bucket[f] > 0 && removed < target) {
                removed += f;
                ans++;
                bucket[f]--;
            }
        }

        return ans;
    }
};