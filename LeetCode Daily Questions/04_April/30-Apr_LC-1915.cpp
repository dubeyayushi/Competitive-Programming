// https://leetcode.com/problems/number-of-wonderful-substrings/description/

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ans = 0;
        int n = word.size();
        int arr[1024];
        arr[0] = 1;
        int sum = 0;
        for (int ch : word){
            int idx = ch - 'a';
            sum = (sum ^ (1<<idx));
            ans += arr[sum];
            for (int i = 0; i<10; i++){
                ans += arr[(sum^(1<<i))];
            }
            arr[sum]++;
        }
        return ans;
    }
};