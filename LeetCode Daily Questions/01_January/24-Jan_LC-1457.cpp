// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/description/?envType=daily-question&envId=2024-01-24

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
    void helper(TreeNode* root, unordered_map<int, int>mp, int& ans){
        if (root == NULL){
            return;
        }
        if (root->left==NULL && root->right==NULL){
            mp[root->val]++;
            int temp = 0;
            for (auto ele : mp){
                if (ele.second%2!=0){
                    temp++;
                }
            }
            if (temp<=1){
                ans++;
            }
            return;
        }
        mp[root->val]++;
        helper(root->left, mp, ans);
        helper(root->right, mp, ans);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int, int>mp;
        int ans = 0;
        helper(root, mp, ans);
        return ans;
    }
};