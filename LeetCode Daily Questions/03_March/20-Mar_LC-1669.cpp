// https://leetcode.com/problems/merge-in-between-linked-lists/description/?envType=daily-question&envId=2024-02-23

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp = list1;
        ListNode* tail2 = list2;
        while(tail2->next!=NULL){
            tail2 = tail2->next;
        }
        int count = 0;
        while(count!=a-1){
            temp = temp->next;
            count++;
        }
        ListNode* start = temp;
        while(count!=b+1){
            temp = temp->next;
            count++;
        }
        tail2->next = temp;
        start->next = list2;
        return list1;
    }
};