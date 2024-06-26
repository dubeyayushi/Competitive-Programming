// https://leetcode.com/problems/add-two-numbers/description/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0); 
        ListNode* current = dummy; 
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;

        while (temp1 != nullptr || temp2 != nullptr) {
            int num1 = (temp1 != nullptr) ? temp1->val : 0;
            int num2 = (temp2 != nullptr) ? temp2->val : 0;
            int sum = num1 + num2 + carry;
            carry = sum / 10; 
            current->next = new ListNode(sum % 10); 
            current = current->next;

            if (temp1 != nullptr) temp1 = temp1->next;
            if (temp2 != nullptr) temp2 = temp2->next;
        }

        if (carry > 0) {
            current->next = new ListNode(carry);
        }

        return dummy->next; 
    }
};
