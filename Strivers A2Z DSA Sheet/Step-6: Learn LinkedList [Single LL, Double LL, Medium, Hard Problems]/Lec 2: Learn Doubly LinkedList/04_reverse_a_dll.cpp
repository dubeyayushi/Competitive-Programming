// https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=reverse-a-doubly-linked-list

/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
*/
class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        //Your code here
        Node* temp = head;
        while(temp){
            head = temp;
            Node* temp2 = temp->next;
            temp-> next = temp->prev;
            temp->prev = temp2;
            temp = temp->prev;
        }
        return head;
    }
};