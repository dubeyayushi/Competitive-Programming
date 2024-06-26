// https://leetcode.com/problems/balance-a-binary-search-tree/description/

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
    void helper(TreeNode* root, vector<int>& v){
        if (root==NULL){
            return;
        }
        helper(root->left, v);
        v.push_back(root->val);
        helper(root->right, v);
    }
    TreeNode* construct(vector<int> v, int lo, int hi){
        if (lo>hi){
            return NULL;
        }
        int mid = lo + (hi-lo)/2;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = construct(v, lo, mid-1);
        root->right = construct(v, mid+1, hi);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>v;
        helper(root, v);
        int n = v.size();
        return construct(v, 0, n-1);
    }
};