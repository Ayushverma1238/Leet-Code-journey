class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        for(int i = 0; i< m; i++){
            string aux = "";
            for(int j = 0; j < n; j++){
                if(i == 0){
                    aux += '.';
                }else if(j == n-1){
                    aux += '.';
                }else{
                    aux += '#';
                }
            }
            ans.push_back(aux);
        }
        return ans;
    }
};