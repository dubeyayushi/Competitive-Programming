#include<iostream>
using namespace std;
 
class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void printElementsOfNthLevel(TreeNode* root, int level, int k){
    if (root==NULL){
        return;
    }
    if (k==level){
        cout << root->val << " ";
    }
    printElementsOfNthLevel(root->left, level, k+1);
    printElementsOfNthLevel(root->right, level, k+1);
}

int main(){
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(4);
    TreeNode* e = new TreeNode(5);
    TreeNode* f = new TreeNode(6);
    TreeNode* g = new TreeNode(7);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    printElementsOfNthLevel(a, 2, 0);
}