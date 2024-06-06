// https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=delete-node-in-doubly-linked-list

/* Structure of Node
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  
  Node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }
  
};
*/

class Solution
{
    public:
    Node* deleteNode(Node *head_ref, int x)
    {
      //Your code here
      int count = 1;
      Node* temp = head_ref;
      if (x==1){
          head_ref = head_ref -> next;
          head_ref->prev = NULL;
          temp->next = NULL;
          return head_ref;
      }
      while(temp){
          if (x==count){
              if (temp->prev) temp->prev->next = temp->next;
              if (temp->next) temp->next->prev = temp->prev;
              temp->prev = NULL;
              temp->next = NULL;
              break;
          }
          temp = temp->next;
          count++;
      }
      return head_ref;
    }
};