class Solution {
public:
    string largestMerge(string word1, string word2) {
        string merge = "";
        int i = 0,j = 0;
        int n1 = word1.size(), n2 = word2.size();
        while(i < n1 && j < n2){
            if(word1[i] > word2[j]){
                merge += word1[i++];
            }else if(word1[i] < word2[j]){
                merge += word2[j++];
            }else{
                int x = i, y = j;
                bool check = true;
                for(; x < n1 && y < n2;x++, y++){
                    if(word1[x] == word2[y])
                        continue;
                    else{
                        check = true;
                        break;
                    }
                }
                if(check && word1[x] > word2[y]){
                    merge += word1[i++];
                }else{
                    merge += word2[j++];
                }
            }
        }
        merge += word1.substr(i, n1- i);
        merge += word2.substr(j, n2 - j);
        return merge;
    }
};