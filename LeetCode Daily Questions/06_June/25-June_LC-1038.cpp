// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/

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
    int sum = 0;
    void inorderTraversal(TreeNode* root){
        if (root==NULL){
            return;
        }
        inorderTraversal(root->right);
        root->val += sum;
        sum = root->val;
        inorderTraversal(root->left);
    }

    TreeNode* bstToGst(TreeNode* root) {
        inorderTraversal(root);
        return root;
    }
};