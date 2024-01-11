//https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/?envType=daily-question&envId=2024-01-11

#include<iostream>
using namespace std;
 
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
    int diff = 0;
    void difference(TreeNode* root, int maxEle, int minEle){
        if (root==NULL){
            return;
        }
        diff = max(diff, max(abs(minEle - root->val), abs(maxEle - root->val)));
        minEle = min(minEle, root->val);
        maxEle = max(maxEle, root->val);
        difference(root->left, maxEle, minEle);
        difference(root->right, maxEle, minEle);
    }
    int helper(TreeNode* root){
        if (root==NULL){
            return 0;
        }
        int maxEle = root->val;
        int minEle = root->val;
        difference(root, maxEle, minEle);
        return diff;
    }
    int maxAncestorDiff(TreeNode* root) {
        return helper(root);
    }
};