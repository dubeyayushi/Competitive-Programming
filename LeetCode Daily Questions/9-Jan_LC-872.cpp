//https://leetcode.com/problems/leaf-similar-trees/description/?envType=daily-question&envId=2024-01-09

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
public:
    void helper(vector<int>&v, TreeNode* root){
        if (root==NULL){
            return;
        }
        if (root->left==NULL && root->right==NULL){
            v.push_back(root->val);
        }
        helper(v, root->left);
        helper(v, root->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>v1;
        vector<int>v2;
        helper(v1, root1);
        helper(v2, root2);
        int n = v1.size();
        int m = v2.size();
        if (n!=m){
            return false;
        }
        for(int i = 0; i<n; i++){
            if (v1[i] != v2[i]){
                return false;
            }
        }
        return true;
    }
};