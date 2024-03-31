// https://leetcode.com/problems/even-odd-tree/description/?envType=daily-question&envId=2024-02-23

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
    bool isEvenOddTree(TreeNode* root) {
        if (root==NULL) return true;
        queue<TreeNode*>q;
        bool flag = true;   //true->even, false->odd
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            int prev = flag ? INT_MIN : INT_MAX;
            for (int i = 0; i<len; i++){
                TreeNode* front = q.front();
                q.pop();
                if (flag){
                    if (front->val%2==0 || front->val<=prev){
                        return false;
                    }
                }
                else{
                    if (front->val%2!=0 || front->val>=prev){
                        return false;
                    }
                }
                if (front->left){
                    q.push(front->left);
                }
                if (front->right){
                    q.push(front->right);
                }
                prev = front->val;
            }
            flag = !flag;
        }
        return true;
    }
};