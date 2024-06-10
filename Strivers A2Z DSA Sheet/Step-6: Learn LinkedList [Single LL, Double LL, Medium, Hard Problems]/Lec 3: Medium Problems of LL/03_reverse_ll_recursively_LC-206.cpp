// https://leetcode.com/problems/reverse-linked-list/description/

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
    ListNode* helper(ListNode* head, ListNode* curr, ListNode* prev, ListNode* forward){
        if (curr==NULL) return head;
        head = curr;
        curr->next = prev;
        prev = curr;
        curr = forward;
        if (forward) forward = forward->next;
        return helper(head, curr, prev, forward);
    }
    ListNode* reverseList(ListNode* head) {
        if (head==NULL) return head;
        return helper(head, head, NULL, head->next);
    }
};