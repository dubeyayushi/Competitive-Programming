#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
 
class Node{
public:
    int val;
    Node* right;
    Node* left;
    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void leftBoundary(Node* root, vector<int>& left){
    if ((root==NULL) || (root->left==NULL && root->right==NULL)){
        return;
    }
    left.push_back(root->val);
    leftBoundary(root->left, left);
}

void rightBoundary(Node* root, vector<int>& right){
    if ((root==NULL) || (root->left==NULL && root->right==NULL)){
        return;
    }
    right.push_back(root->val);
    rightBoundary(root->right, right);
}

void leafBoundary(Node* root, vector<int>& leaf){
    if (root==NULL){
        return;
    }
    if (root->left==NULL && root->right==NULL){
        leaf.push_back(root->val);
        return;
    }
    leafBoundary(root->left, leaf);
    leafBoundary(root->right, leaf);
}

void boundaryTraversal(Node* root){
    vector<int>left;
    vector<int>right;
    vector<int>leaf;
    vector<int>ans;
    leftBoundary(root, left);
    rightBoundary(root, right);
    leafBoundary(root, leaf);
    for (int i = 0; i<left.size(); i++){
        ans.push_back(left[i]);
    }
    for (int i = 0; i<leaf.size(); i++){
        ans.push_back(leaf[i]);
    }
    for (int i = right.size()-1; i>0; i--){
        ans.push_back(right[i]);
    }
    for (int i = 0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;

}

Node* construct(int arr[], int n){
    queue<Node*>q;
    Node* root = new Node(arr[0]);
    q.push(root);
    int i = 1;
    int j = 2;
    while(q.size()>0 && i<n){
        Node* temp = q.front();
        q.pop();
        Node* l;
        Node* r;
        if (arr[i] != INT_MIN){
            l = new Node(arr[i]);
        }
        else{
            l = NULL;
        }
        if (j!=n && arr[j] != INT_MIN){
            r = new Node(arr[j]);
        }
        else{
            r = NULL;
        }
        temp->left = l;
        temp->right = r;
        if (l!=NULL) q.push(l);
        if (r!=NULL) q.push(r);
        i+=2;
        j+=2;
    }
    return root;
}
    


int main(){
    //construct
    int arr[] = {1,2,3,4,5, INT_MIN, 6, INT_MIN, INT_MIN, 7, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = construct(arr, n);
    boundaryTraversal(root);
}