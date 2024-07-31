// https://leetcode.com/problems/delete-nodes-and-return-forest/description/?envType=daily-question&envId=2024-07-17

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
    TreeNode* traverse(TreeNode* root, unordered_set<int>s, vector<TreeNode*> & result){
        if (root==NULL){
            return NULL;
        }

        root->left = traverse(root->left, s, result);
        root->right = traverse(root->right,s, result);

        if (s.find(root->val)!=s.end()){
            if (root->left) result.push_back(root->left);
            if (root->right) result.push_back(root->right);
            return NULL;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>result;
        unordered_set<int>s;
        for (int i = 0; i<to_delete.size(); i++){
            s.insert(to_delete[i]);
        }
        if (s.find(root->val)==s.end()) result.push_back(root);
        traverse(root, s, result);
        return result;
    }
};