// https://www.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=insert-a-node-in-doubly-linked-list

/* a Node of the doubly linked list 
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

//Function to insert a new node at given position in doubly linked list.
void addNode(Node *head, int pos, int data)
{
   // Your code here
   if (head==NULL){
       head = new Node(data);
       return;
   }
   Node* temp = head;
   int count = 0;
   Node* prevNode = NULL;
   Node* nextNode = NULL;
   while(temp){
       if (pos==count){
           prevNode = temp;
           nextNode = temp->next;
           break;
       }
       temp = temp->next;
       count++;
   }
   Node* newnode = new Node(data);
   prevNode->next = newnode;
   if (nextNode) nextNode->prev = newnode;
   newnode->prev = prevNode;
   newnode->next = nextNode;
}