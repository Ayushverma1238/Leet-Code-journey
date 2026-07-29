class Solution {
    long long countPermutations(const vector<int> & count, long long k_cap){
        long long total = 0;
        for(auto c : count) total += c;
        long long ans = 1;
        int curr_total = 0;
        for(int c: count){
            if(c == 0) continue;
            for(int j = 1; j <= c; j++){
                curr_total++;
                ans = (ans * curr_total)/j;
                if(ans > k_cap) return k_cap + 1;
            }
        }
        return ans;
    }
public:
    string smallestPalindrome(string s, int k) {
        int n = s.size();
        vector<int> freq(26, 0);
        for(auto c : s){
            freq[c-'a']++;
        }

        vector<int> halfCount(26,0);
        char midChar = 0;
        for(int i = 0; i < 26; i++){
            halfCount[i] = freq[i]/2;
            if(freq[i]%2 != 0){
                midChar = 'a' + i;
            }
        }
        int halfLen = n/2;
        string firstHalf= "";
        long long currK = k;
        for(int i = 0; i < halfLen; i++){
            bool placed = false;
            for(auto j = 0; j< 26; j++){
                if(halfCount[j] == 0) continue;
                halfCount[j]--;
                long long ways = countPermutations(halfCount, currK);
                if(ways >= currK){
                    firstHalf += (char)('a' + j);
                    placed= true;
                    break;
                }else{
                    currK -= ways;
                    halfCount[j]++;
                }
            }
            if(!placed) return "";
        }
        string secondHalf = firstHalf;
        reverse(secondHalf.begin(), secondHalf.end());
        if(midChar != 0){
            return firstHalf + midChar + secondHalf;
        }
        return firstHalf + secondHalf;

    }
};