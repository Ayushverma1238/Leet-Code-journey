class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size();
        int sum = skill[0] + skill[n-1];
        int i = 0, j = n-1;
        long long ans = 0;
        while(i < j){
            int aux = skill[i] + skill[j];
            if(sum == aux){
                ans += (1LL * skill[i] * skill[j]);
            }else{
                return -1;
            }
            i++;
            j--;
        }
        return ans;
        
    }
};