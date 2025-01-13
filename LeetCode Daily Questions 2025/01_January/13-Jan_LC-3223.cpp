// https://leetcode.com/problems/minimum-length-of-string-after-operations/description/

class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, vector<int>> mp;
        
        for (int i = 0; i < s.length(); i++) {
            mp[s[i]].push_back(i);
        }
        
        set<int> removedIndices;
        
        for (auto entry : mp) {
            vector<int> &indices = entry.second;
            if (indices.size() >= 3) {
                int left = 0, right = indices.size() - 1;
                while (left < right - 1) {
                    if (removedIndices.find(indices[left]) == removedIndices.end() && 
                        removedIndices.find(indices[right]) == removedIndices.end()) {
                        removedIndices.insert(indices[left]);
                        removedIndices.insert(indices[right]);
                        left++;
                        right--;
                    } else {
                        break;
                    }
                }
            }
        }
        
        int ans = s.length() - removedIndices.size();
        
        return ans;
    }
};