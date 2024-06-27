// https://leetcode.com/problems/reverse-nodes-in-k-group/description/

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
    ListNode* reverseLL(ListNode* temp){
        ListNode* curr = temp;
        ListNode* prev = NULL;
        while(curr){
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }
    ListNode* getKNode(ListNode* temp, int k){
        k -= 1;
        while(temp && k>0){
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        while(temp){
            ListNode* kNode = getKNode(temp, k);
            if (kNode == NULL){
                if (prevNode) prevNode->next = temp;
                break;
            }
            ListNode* nextNode = kNode->next;
            kNode->next = NULL;
            reverseLL(temp);
            if (temp==head){
                head = kNode;
            }
            else{
                prevNode->next = kNode;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};

