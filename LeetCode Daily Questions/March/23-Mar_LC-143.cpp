// https://leetcode.com/problems/reorder-list/description/?envType=daily-question&envId=2024-02-23

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL, *curr = head, *Next = head;
        while(curr){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* c = slow->next;
        slow->next = NULL;
        c = reverseList(c);
        ListNode* temp1 = head;
        ListNode* temp2 = c;
        while(temp1!=NULL && temp2!=NULL){
            ListNode* temp3 = temp1->next;
            ListNode* temp4 = temp2->next;
            temp1->next = temp2;
            temp2->next = temp3;
            temp1 = temp3;
            temp2 = temp4;
        }
    }
};

