// https://leetcode.com/problems/same-tree/description/?envType=daily-question&envId=2024-02-23

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p==NULL && q==NULL){
            return true;
        }
        else if (p==NULL || q==NULL){
            return false;
        }
        if (p->val!=q->val){
            return false;
        }
        bool lst_ans = isSameTree(p->left, q->left);
        if (lst_ans == false){
            return false;
        }
        bool rst_ans = isSameTree(p->right, q->right);
        if (rst_ans == false){
            return false;
        }
        return true;
    }
};