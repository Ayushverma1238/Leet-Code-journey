class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> evenF, oddF;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) evenF[nums[i]]++;
            else oddF[nums[i]]++;
        }

        int e1 = 0, cntE1 = 0, e2 = 0, cntE2 = 0;
        for (auto& [val, count] : evenF) {
            if (count > cntE1) {
                e2 = e1; cntE2 = cntE1;
                e1 = val; cntE1 = count;
            } else if (count > cntE2) {
                e2 = val; cntE2 = count;
            }
        }

        int o1 = 0, cntO1 = 0, o2 = 0, cntO2 = 0;
        for (auto& [val, count] : oddF) {
            if (count > cntO1) {
                o2 = o1; cntO2 = cntO1;
                o1 = val; cntO1 = count;
            } else if (count > cntO2) {
                o2 = val; cntO2 = count;
            }
        }

        if (e1 != o1) {
            return n - (cntE1 + cntO1);
        }

        int maxKept = max(cntE1 + cntO2, cntE2 + cntO1);
        return n - maxKept;
    }
};