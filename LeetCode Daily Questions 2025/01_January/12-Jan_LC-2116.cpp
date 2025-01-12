// https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/description/

class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.length()%2!=0) return false;

        stack<int>openBrackets;;
        stack<int>unlocked;

        for (int i = 0; i<s.length(); i++){
            if (locked[i]=='0'){
                unlocked.push(i);
            }
            else if (s[i]=='('){
                openBrackets.push(i);
            }
            else if (s[i]==')'){
                if (!openBrackets.empty()){
                    openBrackets.pop();
                }
                else if (openBrackets.empty() && !unlocked.empty()){
                    unlocked.pop();
                }
                else{
                    return false;
                }
            }
        }
        while(!openBrackets.empty() && !unlocked.empty() && openBrackets.top() < unlocked.top()){
            openBrackets.pop();
            unlocked.pop();
        }
        if (!openBrackets.empty()){
            return false;
        }
        return true;
    }
};