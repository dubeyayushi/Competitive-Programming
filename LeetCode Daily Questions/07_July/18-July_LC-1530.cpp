// https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/?envType=daily-question&envId=2024-07-18

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
    void findLeaves(TreeNode* node, vector<TreeNode*>path, vector<TreeNode*>&leaves, unordered_map<TreeNode*, vector<TreeNode*>>&mp){
        if (!node) return;
        path.push_back(node);
        if (!node->left && !node->right){
            mp[node] = path;
            leaves.push_back(node);
            return;
        }
        findLeaves(node->left, path, leaves, mp);
        findLeaves(node->right, path, leaves, mp);
    }
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        unordered_map<TreeNode*, vector<TreeNode*>>mp;
        vector<TreeNode*> leaves;
        findLeaves(root, {}, leaves, mp);
        for (int i = 0; i<leaves.size(); i++){
            for (int j = i+1; j<leaves.size(); j++){
                vector<TreeNode*> list_i = mp[leaves[i]];
                vector<TreeNode*> list_j = mp[leaves[j]];
                for (int k = 0; k<min(list_i.size(), list_j.size()); k++){
                    if (list_i[k]!=list_j[k]){
                        int dist = list_i.size() - k + list_j.size() - k;
                        if (dist<=distance) ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

