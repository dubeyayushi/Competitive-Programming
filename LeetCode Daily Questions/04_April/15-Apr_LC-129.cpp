// https://leetcode.com/problems/sum-root-to-leaf-numbers/description/?envType=daily-question&envId=2024-04-15

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
    int helper(TreeNode* root, int ans){
        if (root==NULL) return 0;
        ans = ans*10 + root->val;
        if (root->left==NULL && root->right==NULL){
            return ans;
        }
        int leftPath = helper(root->left, ans);
        int rightPath = helper(root->right, ans);
        return leftPath + rightPath;
    }
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }
};