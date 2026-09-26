/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    map<int, map<int, multiset<int>>> mp;
    void levelOrder(TreeNode * root){
        if(root == nullptr)
            return;
        // node, verticies, level
        using tp = tuple<TreeNode *, int, int>;
        queue<tp> q;
        q.push({root, 0, 0});
        while(!q.empty()){
            auto vals = q.front(); q.pop();
            TreeNode * node = get<0>(vals);
            int vert = get<1>(vals);
            int lev = get<2>(vals);
            mp[vert][lev].insert(node->val);

            if(node->left){
                q.push({node->left, vert-1, lev+1});
            }
            if(node->right){
                q.push({node->right, vert+1, lev+1});
            }
        }
        return;
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        levelOrder(root);
        vector<vector<int>> ans;
        for(auto it : mp){
            vector<int> aux;
            for(auto it2 : it.second){
                for(auto it3: it2.second){
                    aux.push_back(it3);
                }
            }
            ans.push_back(aux);
        }
        return ans;
    }
};