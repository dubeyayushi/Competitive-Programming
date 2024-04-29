#include<iostream>
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

int sizeOfBinaryTree(Node* head){
    if (head==NULL){
        return 0;
    }
    return 1 + sizeOfBinaryTree(head->left) + sizeOfBinaryTree(head->right);
}

int main(){
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    cout << sizeOfBinaryTree(a) << endl;

}