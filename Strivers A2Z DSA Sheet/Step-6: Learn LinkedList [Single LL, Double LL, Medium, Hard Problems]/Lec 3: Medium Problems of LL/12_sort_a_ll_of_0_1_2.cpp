// https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=given-a-linked-list-of-0s-1s-and-2s-sort-it

/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        int countOnes = 0;
        int countZeros = 0;
        int countTwos = 0;
        
        Node* temp = head;
        
        while(temp){
            if (temp->data == 1) countOnes++;
            else if (temp->data == 0) countZeros++;
            else countTwos++;
            
            temp = temp->next;
        }
        
        temp = head;
        while(temp){
            while(countZeros--){
                temp->data = 0;
                temp = temp->next;
            }
            while(countOnes--){
                temp->data = 1;
                temp = temp->next;
            }
            while(countTwos--){
                temp->data = 2;
                temp = temp->next;
            }
        }
        return head;
        
    }
};