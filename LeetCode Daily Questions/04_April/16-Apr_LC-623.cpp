// https://leetcode.com/problems/add-one-row-to-tree/description/

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
    TreeNode* helper(TreeNode* root, int val, int depth, int currDepth){
        if (root==NULL) return root;
        if (depth-1==currDepth){
            TreeNode* nodeLeft = new TreeNode(val);
            TreeNode* nodeRight = new TreeNode(val);
            nodeLeft->left = root->left;
            nodeRight->right = root->right;
            root->left = nodeLeft;
            root->right = nodeRight;
            return root;
        }
        root->left = helper(root->left, val, depth, currDepth + 1);
        root->right = helper(root->right, val, depth, currDepth + 1);
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth==1){
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        return helper(root, val, depth, 1);
    }
};