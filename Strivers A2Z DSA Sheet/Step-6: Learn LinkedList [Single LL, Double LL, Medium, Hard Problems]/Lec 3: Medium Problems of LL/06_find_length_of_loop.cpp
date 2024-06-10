// https://www.geeksforgeeks.org/problems/find-length-of-loop/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-length-of-loop

/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

//Function to find the length of a loop in the linked list.
int countNodesinLoop(struct Node *head)
{
    // Code here
    Node* fast = head;
    Node* slow = head;
    bool isCycle = false;
    
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if (slow==fast) {
            isCycle = true;
            break;
        }
    }
    if (!isCycle) return 0;
    
    Node* temp = head;
    while(temp!=slow){
        temp = temp->next;
        slow = slow->next;
    }
    int ans = 1;
    temp = temp->next;
    while(temp!=slow){
        ans++;
        temp = temp->next;
    }
    return ans;
}