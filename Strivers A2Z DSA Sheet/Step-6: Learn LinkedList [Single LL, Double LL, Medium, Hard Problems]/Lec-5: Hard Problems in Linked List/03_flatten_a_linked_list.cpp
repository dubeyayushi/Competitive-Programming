// https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=flattening-a-linked-list

/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

Node* merge(Node* list1, Node* list2){
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;
    
    while(list1 && list2){
        if (list1->data < list2->data){
            res->bottom = list1;
            res = list1;
            list1 = list1->bottom;
        }
        else{
            res->bottom = list2;
            res = list2;
            list2 = list2->bottom;
        }
        res->next = NULL;
    }
    if (list1) res->bottom = list1;
    else res->bottom = list2;
    if (dummyNode->bottom) dummyNode->bottom->next = NULL;
    return dummyNode->bottom;
}

/*  Function which returns the  root of
    the flattened linked list. */
Node *flatten(Node *root) {
    // Your code here
    if (root == NULL || root->next==NULL) return root;
    
    Node* mergedList = flatten(root->next);
    
    root = merge(mergedList, root);
    return root;
}