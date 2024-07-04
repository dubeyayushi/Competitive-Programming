class Solution {
public:
    unordered_map<char, vector<char>>mp;

    void helper(string digits, int idx, vector<string>&result, string str){
        if (idx==digits.length()){
            result.push_back(str);
            return;
        }
        char num = digits[idx];
        for (char ch : mp[num]){
            helper(digits, idx+1, result, str+ch);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string>result;
        if (digits.empty()) return result;
        mp['2'] = {'a', 'b', 'c'};
        mp['3'] = {'d', 'e', 'f'};
        mp['4'] = {'g', 'h', 'i'};
        mp['5'] = {'j', 'k', 'l'};
        mp['6'] = {'m', 'n', 'o'};
        mp['7'] = {'p', 'q', 'r', 's'};
        mp['8'] = {'t', 'u', 'v'};
        mp['9'] = {'w', 'x', 'y', 'z'};
        helper(digits, 0, result, "");
        return result;
    }
};