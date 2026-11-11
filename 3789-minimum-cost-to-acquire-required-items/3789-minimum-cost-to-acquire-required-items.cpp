class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans1 = 1LL* cost1 * need1 + 1LL * cost2 * need2;
        long long ans2 = 1LL * costBoth * min(need1, need2);
        if(need1 < need2){
            ans2 += (need2 - need1)* 1LL * cost2;
        }else if(need1 > need2){
            ans2 += (need1 - need2) * 1LL * cost1;
        }

        long long ans3 = costBoth * 1LL * max(need1, need2);
        return min({ans1, ans2, ans3});

    }
};