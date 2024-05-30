// https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ans = 0;
        vector<int>prefix(arr.begin(), arr.end());
        prefix.insert(prefix.begin(), 0);
        for (int i = 1; i<prefix.size(); i++){
            prefix[i] ^= prefix[i-1];
        }
        for (int start = 0; start<prefix.size(); start++){
            for (int end = start+1; end<prefix.size(); end++){
                if (prefix[start]==prefix[end]){
                    ans += end - start - 1;
                }
            }
        }
        return ans;
    }
};