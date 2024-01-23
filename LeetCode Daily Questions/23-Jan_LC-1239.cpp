// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/?envType=daily-question&envId=2024-01-23

class Solution {
public:
    int max(int a, int b){
        if (a>b){
            return a;
        }
        return b;
    }
    void dfs(vector<string>& arr, const string& path, int idx, int& ans){
        if (isUniqueChars(path)){
            ans = max(ans, path.length());
        }
        if (idx == arr.size() || !isUniqueChars(path)){
            return;
        }
        for (int i = idx; i<arr.size(); i++){
            dfs(arr, path+arr[i], i+1, ans);
        }
    }
    bool isUniqueChars(const string& str){
        unordered_set<char>s;
        for (char c : str){
            if (s.count(c)){
                return false;
            }
            s.insert(c);
        }
        return true;
    }
    int maxLength(vector<string>& arr) {
        int ans = 0;
        dfs(arr, "", 0, ans);
        return ans;
    }
};