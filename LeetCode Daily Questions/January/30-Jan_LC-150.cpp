// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/?envType=daily-question&envId=2024-01-30

class Solution {
public:
    int f(int a, int b, string str){
        if (str=="+"){
            return a + b;
        }
        else if (str=="-"){
            return a - b;
        }
        else if (str=="*"){
            return a * b;
        }
        else{
            return a / b;
        }
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for (int i = 0; i<tokens.size(); i++){
            if (tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(f(b, a, tokens[i]));
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};