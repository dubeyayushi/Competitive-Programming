// https://leetcode.com/problems/add-two-numbers-ii/description/

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
 #define ll long long int
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>st1;
        stack<int>st2;
        vector<int>sumDigits;
        ListNode* result = new ListNode();
        while(l1!=NULL){
            st1.push(l1->val);
            l1 = l1->next;
        }
        while(l2!=NULL){
            st2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        while(!st1.empty() && !st2.empty()){
            int digitSum = carry + st1.top() + st2.top();
            st1.pop();
            st2.pop();
            sumDigits.push_back(digitSum%10);
            carry = digitSum/10;
        }
        while(!st1.empty()){
            int digitSum = carry + st1.top();
            st1.pop();
            sumDigits.push_back(digitSum%10);
            carry = digitSum/10;
        }
        while(!st2.empty()){
            int digitSum = carry + st2.top();
            st2.pop();
            sumDigits.push_back(digitSum%10);
            carry = digitSum/10;
        }
        if (carry>0){
            sumDigits.push_back(carry);
        }
        ListNode* temp = new ListNode(sumDigits[sumDigits.size()-1]);
        result = temp;
        for (int i = sumDigits.size()-2; i>=0; i--){
            ListNode* newnode = new ListNode(sumDigits[i]);
            temp->next = newnode;
            temp = temp->next;
        }
        return result;
    }
};