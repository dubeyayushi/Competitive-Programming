// https://leetcode.com/problems/expression-add-operators/

class Solution {
public: 
    void helper(vector<string>& result, string num, int target, int idx, long long current_val, long long last_operand, string expression) {
        if (idx == num.size()) {
            if (current_val == target) {
                result.push_back(expression);
            }
            return;
        }

        for (int i = idx; i < num.size(); ++i) {
            // Avoid numbers with leading zeros
            if (i != idx && num[idx] == '0') break;
            
            string current_num_str = num.substr(idx, i - idx + 1);
            long long current_num = stoll(current_num_str);

            if (idx == 0) {
                // Starting case, the first number in the expression
                helper(result, num, target, i + 1, current_val + current_num, current_num, current_num_str);
            } else {
                // Addition
                helper(result, num, target, i + 1, current_val + current_num, current_num, expression + "+" + current_num_str);

                // Subtraction
                helper(result, num, target, i + 1, current_val - current_num, -current_num, expression + "-" + current_num_str);

                // Multiplication
                helper(result, num, target, i + 1, current_val - last_operand + last_operand * current_num, last_operand * current_num, expression + "*" + current_num_str);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> result;
        if (num.empty()) return result;

        helper(result, num, target, 0, 0, 0, "");
        return result;
    }
};
