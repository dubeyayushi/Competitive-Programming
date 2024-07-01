// https://www.geeksforgeeks.org/problems/reverse-a-stack/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=reverse-a-stack

class Solution{
public:
    void helper(stack<int> &St, int curr){
        if (St.empty()){
            St.push(curr);
            return;
        }
        int front = St.top();
        St.pop();
        helper(St, curr);
        St.push(front);
    }
    void Reverse(stack<int> &St){
        if (!St.empty()){
            int curr = St.top();
            St.pop();
            Reverse(St);
            helper(St, curr);
        }
    }
};