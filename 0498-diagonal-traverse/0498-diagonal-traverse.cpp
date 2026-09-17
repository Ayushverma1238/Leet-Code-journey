class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();       // number of rows
        int n = mat[0].size();    // number of columns
        vector<int> result;
        
        for(int i= 0;i< m+n-1; i++){
            int row, col;
            if(i%2==0){
                row = (i < m) ? i : m - 1;
                col = i - row;
                while(row>=0 && col<n){
                    result.push_back(mat[row][col]);
                    row--;
                    col++;
                }
            }
            else{
                col = (i<n) ? i:n-1;
                row= i-col;
                while(col >= 0 && row < m){
                    result.push_back(mat[row][col]);
                    row++;
                    col--;
                }
            }
        }
        return result;
    }
};
