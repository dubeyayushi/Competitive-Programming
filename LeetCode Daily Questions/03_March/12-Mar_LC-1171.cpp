// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/?envType=daily-question&envId=2024-02-23

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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* front = new ListNode(0, head);
        ListNode* start = front;

        while (start != nullptr) {
            int prefixSum = 0;
            ListNode* end = start->next;

            while (end != nullptr) {
                // Add end's value to the prefix sum
                prefixSum += end->val;
                // Delete zero sum consecutive sequence 
                // by setting node before sequence to node after
                if (prefixSum == 0) {
                    start->next = end->next;
                }
                end = end->next;
            }

            start = start->next;
        }
        return front->next;
    }
};