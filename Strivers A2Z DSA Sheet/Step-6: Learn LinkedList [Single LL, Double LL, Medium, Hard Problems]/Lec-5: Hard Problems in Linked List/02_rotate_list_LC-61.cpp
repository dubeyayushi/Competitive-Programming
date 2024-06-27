// https://leetcode.com/problems/rotate-list/description/

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
    ListNode* findLastNode(ListNode* temp, int k){
        for (int i = 1; i<k; i++){
            temp = temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==NULL || head->next==NULL) return head;

        int len = 1;
        ListNode* temp = head;
        while(temp->next){
            len++;
            temp = temp->next;
        }
        if (k==len) return head;
        else if (k>len) k = k%len;
        temp->next = head;
        temp = head;
        ListNode* lastNode = findLastNode(temp, len-k);
        head = lastNode->next;
        lastNode->next = NULL;
        return head;
    }
};