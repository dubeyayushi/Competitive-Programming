// https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list

// User function Template for C++


/* a Node of the doubly linked list 
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // Write your code here
        Node* temp = *head_ref;
        while(temp && temp->data==x){
            *head_ref = temp->next;
            if (temp->next){
                temp->next->prev = NULL;
            }
            temp = *head_ref;
        }
        while (temp) {
            if (temp->data == x) {
                Node* next_node = temp->next;
                if (temp->prev) {
                    temp->prev->next = temp->next;
                }
                if (temp->next) {
                    temp->next->prev = temp->prev;
                }
                temp = next_node;
            } else {
                temp = temp->next;
            }
        }
    }
};