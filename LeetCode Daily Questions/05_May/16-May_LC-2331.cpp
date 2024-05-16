// https://leetcode.com/problems/evaluate-boolean-binary-tree/description/

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
    bool evaluateTree(TreeNode* root) {
        if (root->left==NULL && root->right==NULL) return root->val;
        if (root->left->left==NULL && root->left->right==NULL && root->right->left==NULL && root->right->right==NULL){
            if (root->val==2) return root->left->val || root->right->val;
            return root->left->val && root->right->val;
        }
        bool leftVal = evaluateTree(root->left);
        bool rightVal = evaluateTree(root->right);
        if (root->val==2) return leftVal || rightVal;
        return leftVal && rightVal;
    }
};