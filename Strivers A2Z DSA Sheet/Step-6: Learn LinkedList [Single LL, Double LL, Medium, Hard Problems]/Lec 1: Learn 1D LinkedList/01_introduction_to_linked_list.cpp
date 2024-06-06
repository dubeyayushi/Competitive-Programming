// https://www.geeksforgeeks.org/problems/introduction-to-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=introduction-to-linked-list

class Solution {
  public:
    Node* constructLL(vector<int>& arr) {
        // code here
        Node* head = new Node(arr[0]);
        Node* temp = head;
        for (int i = 1; i<arr.size(); i++){
            Node* newnode = new Node(arr[i]);
            temp->next = newnode;
            temp = temp->next;
        }
        return head;
    }
};