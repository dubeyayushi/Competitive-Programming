#include<iostream>
#include<queue>
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

void levelOrderTraversalUsingQueue(TreeNode* root){ //BFS
    queue<TreeNode*>q;
    q.push(root);
    while(q.size()){
        TreeNode* temp = q.front();
        q.pop();
        cout << temp->val << " ";
        if (temp->left!=NULL){
            q.push(temp->left);
        }
        if (temp->right!=NULL){
            q.push(temp->right);
        }
    }
    cout << endl;
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
    levelOrderTraversalUsingQueue(a);
}