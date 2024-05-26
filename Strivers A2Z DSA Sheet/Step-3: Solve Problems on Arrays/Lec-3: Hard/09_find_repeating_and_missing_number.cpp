// https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-missing-and-repeating

class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        unordered_set<int>s;
        vector<int>ans;
        for (int i = 0; i<arr.size(); i++){
            if (s.find(arr[i])==s.end()){
                s.insert(arr[i]);
            }
            else{
                ans.push_back(arr[i]);
            }
        }
        for (int i = 1; i<=n; i++){
            if (s.find(i)==s.end()){
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }   
};
