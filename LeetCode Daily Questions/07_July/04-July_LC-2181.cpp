// https://leetcode.com/problems/merge-nodes-in-between-zeros/description/

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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* newHead = new ListNode(-1);
        ListNode* temp2 = newHead;
        ListNode* temp = head;
        int sum = 0;
        while(temp){
            sum += temp->val;
            if (temp->val==0 && sum!=0){
                ListNode* newnode = new ListNode(sum);
                temp2->next = newnode;
                temp2 = temp2->next;
                sum = 0;
            }
            temp = temp->next;
        }
        return newHead->next;
    }
};