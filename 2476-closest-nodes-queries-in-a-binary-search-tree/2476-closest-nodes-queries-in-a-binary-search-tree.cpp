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
private:
    vector<int> nums;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        nums.push_back(root->val);
        inorder(root->right);
    }

public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        nums.clear();
        inorder(root);
        
        int n = nums.size();
        vector<vector<int>> ans;
        ans.reserve(queries.size());

        for (int q : queries) {
            auto it = lower_bound(nums.begin(), nums.end(), q);
            
            int mini = -1;
            int maxi = -1;

            if (it != nums.end()) {
                maxi = *it; // Smallest value >= q
                if (*it == q) {
                    mini = q;
                } else if (it != nums.begin()) {
                    mini = *(it - 1); // Largest value <= q
                }
            } else {
                // q is strictly greater than all elements in the BST
                mini = nums.back();
            }

            ans.push_back({mini, maxi});
        }

        return ans;
    }
};