// https://leetcode.com/problems/diameter-of-binary-tree/description/?envType=daily-question&envId=2024-02-23

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
    int maxDia = 0;
    int levels(TreeNode* head){
        if (head==NULL){
            return 0;
        }
        int leftLevel = levels(head->left);
        int rightLevel = levels(head->right);
        return max(leftLevel, rightLevel) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root==NULL){
            return 0;
        }
        int dia = levels(root->left) + levels(root->right);
        maxDia = max(dia, maxDia);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return maxDia;
    }
};