// https://leetcode.com/problems/smallest-string-starting-from-leaf/description/
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
    vector<string>strings;
    void helper(TreeNode* root, const string& str){
        if (root==NULL) return;
        if (root->left==NULL && root->right==NULL){
            string newstr = str + char('a' + root->val);
            strings.push_back(newstr);
            return;
        }
        helper(root->left, str + char('a' + root->val));
        helper(root->right, str + char('a' + root->val));
    }
    string smallestFromLeaf(TreeNode* root) {
        helper(root, "");
        for (int i = 0; i<strings.size(); i++){
            reverse(strings[i].begin(), strings.end());
        }
        sort(strings.begin(), strings.end());
        return strings[0];
    }
};