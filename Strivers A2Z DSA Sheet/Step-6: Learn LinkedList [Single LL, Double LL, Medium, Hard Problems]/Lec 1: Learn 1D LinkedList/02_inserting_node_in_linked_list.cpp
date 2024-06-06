// https://www.geeksforgeeks.org/problems/linked-list-insertion-1587115620/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=linked-list-insertion

class Solution{
  public:
    //Function to insert a node at the beginning of the linked list.
    Node *insertAtBegining(Node *head, int x) {
       // Your code here
       if (head==NULL) return new Node(x);
       Node* newnode = new Node(x);
       newnode->next = head;
       head = newnode;
       return head;
    }
    
    
    //Function to insert a node at the end of the linked list.
    Node *insertAtEnd(Node *head, int x)  {
       // Your code here
       if (head==NULL) return new Node(x);
       Node* temp = head;
       while(temp->next!=NULL){
           temp = temp->next;
       }
       Node* newnode = new Node(x);
       temp->next = newnode;
       return head;
    }
};
