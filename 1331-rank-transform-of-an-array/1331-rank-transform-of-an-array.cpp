class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>>> pq;
        for(int i=0;i<arr.size();i++){
            pq.push({arr[i],i});
        }
        int rank=1;
        int prev=INT_MIN;
        while(!pq.empty()){
            pair<int,int> x=pq.top();
            pq.pop();
            if(prev==INT_MIN){
                arr[x.second]=rank;
            }
            else if(prev!=x.first){
                rank++;
                arr[x.second]=rank;
            }
            else{
                arr[x.second]=rank;
            }
            prev=x.first;
        }
        return arr;
        
        
    }
};