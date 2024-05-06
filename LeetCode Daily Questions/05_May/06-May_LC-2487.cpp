// https://leetcode.com/problems/remove-nodes-from-linked-list/description/

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
    ListNode* removeNodes(ListNode* head) {
        ListNode* temp = head;
        vector<int>v;
        while(temp){
            v.push_back(temp->val);
            temp = temp->next;
        }
        stack<int>st;
        int n = v.size();
        st.push(v[n-1]);
        for (int i = n-2; i>=0; i--){
            if (v[i]>=st.top()){
                st.push(v[i]);
            }
        }
        temp = head;
        ListNode* t = temp->next;
        if (temp->val!=st.top()){
            while(t->val!=st.top()){
                temp = temp->next;
                t = t->next;
            }
            temp->next = NULL;
            temp = t;
            head = temp;
            t = t->next;
            st.pop();
        }
        else{
            st.pop();
            temp = t;
            t = t->next;
        }
        while(st.size()>0 && t!=NULL){
            if (t->val==st.top()){
                temp->next = t;
                temp = t;
                st.pop();
            }
            t = t->next;
        }

        return head;
    }
};