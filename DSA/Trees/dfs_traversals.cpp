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

void preorder(TreeNode* root){ //root left right
    if (root==NULL){
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(TreeNode* root){ //left right root
    if (root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

void inorder(TreeNode* root){ //left root right
    if (root==NULL){
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
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
    preorder(a);
    cout << endl;
    inorder(a);
    cout << endl;
    postorder(a);
    cout << endl;
}