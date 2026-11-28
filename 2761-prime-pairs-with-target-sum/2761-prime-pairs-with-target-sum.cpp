class Solution {
    vector<int> soe(int n){
        vector<bool> isPrime(n +1, true);
        isPrime[0] = isPrime[1] = false;

        for(int i = 2; i * i <= n; i++){
            if (isPrime[i]){
                for(int j = i *i; j <= n; j+= i){
                    isPrime[j] = false;
                }
            }
        }
        vector<int> ans;
        for(int i =2; i < n; i++){
            if(isPrime[i])
                ans.push_back(i);
        }
        return ans;
    }
public:
    vector<vector<int>> findPrimePairs(int n) {
        if(n <= 2)
            return {};
        vector<int>prime = soe(n);
        int i = 0, j = prime.size()-1;
        vector<vector<int>> ans;
        while(i <= j){
            long long sum =(long long)prime[i] + (long long)prime[j];
            if(sum == n){
                ans.push_back({prime[i], prime[j]});
                i++;
                j--;
            }else if(sum > n){
                j--;
            }else
                i++;
        }
        return ans;
    }
};