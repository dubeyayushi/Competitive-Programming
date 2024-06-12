// https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=remove-duplicates-from-a-sorted-doubly-linked-list

/* struct Node
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

    Node * removeDuplicates(struct Node *head)
    {
        // Your code here
        if (!head || !head->next) return head;
        Node* temp = head->next;
        while(temp){
            if (temp->prev->data == temp->data){
                temp->prev->next = temp->next;
                if (temp->next) temp->next->prev = temp->prev;
                Node* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
            else{
                temp = temp->next;
            }
        }
        return head;
    }
};