// https://www.geeksforgeeks.org/problems/introduction-to-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=introduction-to-doubly-linked-list

/*
class Node{
public:
    Node* prev;
    int data;
    Node* next;
 
    Node()
    { 
        prev = NULL; 
        data = 0;
        next = NULL;
    }
    
    Node(int value)
    { 
        prev = NULL; 
        data = value;
        next = NULL;
    }
};*/

class Solution {
  public:
    Node* constructDLL(vector<int>& arr) {
        // code here
        Node* head = new Node(arr[0]);
        Node* prevNode = head;
        
        for (int i = 1; i<arr.size(); i++){
            Node* newnode = new Node(arr[i]);
            newnode->prev = prevNode;
            prevNode->next = newnode;
            prevNode = prevNode->next;
        }
        return head;
    }
};