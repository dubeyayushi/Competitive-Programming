// https://leetcode.com/problems/sum-of-left-leaves/description/?envType=daily-question&envId=2024-04-14

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
    int helper(TreeNode* root, bool isLeft){
        if (root==NULL) return 0;
        if (root->left==NULL && root->right==NULL){
            return isLeft ? root->val : 0;
        }
        int leftSum = helper(root->left, true);
        int rightSum = helper(root->right, false);
        return leftSum + rightSum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root, false);
    }
};