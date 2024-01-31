// https://leetcode.com/problems/implement-queue-using-stacks/?envType=daily-question&envId=2024-01-29

class MyQueue {
public:
    stack<int>s1;
    stack<int>s2;
    MyQueue() {

    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int n1 = s1.size();
        for (int i = 0; i<n1; i++){
            s2.push(s1.top());
            s1.pop();
        }
        int num = s2.top();
        s2.pop();
        int n2 = s2.size();
        for (int i = 0; i<n2; i++){
            s1.push(s2.top());
            s2.pop();
        }
        return num;
    }
    
    int peek() {
        int n1 = s1.size();
        for (int i = 0; i<n1; i++){
            s2.push(s1.top());
            s1.pop();
        }
        int num = s2.top();
        for (int i = 0; i<n1; i++){
            s1.push(s2.top());
            s2.pop();
        }
        return num;
    }
    
    bool empty() {
        if (s1.size()==0){
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */