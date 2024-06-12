// https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=add-1-to-a-number-represented-as-linked-list

class Solution
{
    public:
    Node* reverseList(Node *head) 
    {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    Node* addOneUtil(Node *head) 
    {
        Node* res = head;
        Node* temp = NULL;
        int carry = 1, sum;
        
        while (head != NULL) {
            sum = carry + head->data;
            carry = (sum >= 10) ? 1 : 0;
            head->data = sum % 10;
            temp = head;
            head = head->next;
        }
        
        if (carry > 0)
            temp->next = new Node(carry);
        
        return res;
    }
    
    Node* addOne(Node *head) 
    {
        head = reverseList(head);
        head = addOneUtil(head);
        head = reverseList(head);
        return head;
    }
};