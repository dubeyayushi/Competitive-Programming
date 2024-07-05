// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans(2, -1);
        vector<int>criticalIdx;
        ListNode* temp = head;
        int size = 0;
        while(temp){
            temp = temp->next;
            size++;
        }
        if (size<=3){
            return ans;
        }
        temp = head;
        int count = 2;
        while(temp->next!=NULL && temp->next->next!=NULL){
            if (((temp->next->val > temp->val) && (temp->next->val > temp->next->next->val)) || ((temp->next->val < temp->val) && (temp->next->val < temp->next->next->val))){
                criticalIdx.push_back(count);
            }
            temp = temp->next;
            count++;
        }
        if (criticalIdx.size()<2){
            return ans;
        }
        if (criticalIdx.size()==2){
            ans[0] = criticalIdx[1]-criticalIdx[0];
            ans[1] = criticalIdx[1]-criticalIdx[0];
            return ans;
        }
        ans[1] = criticalIdx.back() - criticalIdx[0];
        for (int i = 1; i<criticalIdx.size()-1; i++){
            if (ans[0]==1){
                break;
            }
            if ((criticalIdx[i]-criticalIdx[i-1])<=(criticalIdx[i+1]-criticalIdx[i])){
                ans[0] = criticalIdx[i]-criticalIdx[i-1];
            }
            else{
                ans[0] = criticalIdx[i+1]-criticalIdx[i];
            }
        }
        return ans;
    }
};