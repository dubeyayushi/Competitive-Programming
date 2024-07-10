// https://leetcode.com/problems/crawler-log-folder/description/?envType=daily-question&envId=2024-07-10

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int finalPos = 0;
        for (int i = 0; i<logs.size(); i++){
            if (logs[i]=="../"){
                if (finalPos==0){
                    continue;
                }
                else{
                    finalPos--;
                }
            }
            else if (logs[i]=="./"){
                continue;
            }
            else{
                finalPos++;
            }
        }
        return finalPos;
    }
};