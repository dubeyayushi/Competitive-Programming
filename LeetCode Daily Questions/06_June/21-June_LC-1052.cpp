// https://leetcode.com/problems/grumpy-bookstore-owner/description/

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {        
        int currentSum = 0;
        int notGrumpy = 0;
        int notGrumpyWindow = 0;
        for (int i = 0; i<customers.size(); i++){
            if (grumpy[i]==0){
                notGrumpy += customers[i];
            }
        }
        for (int i = 0; i<minutes; i++){
            if (grumpy[i]==0){
                notGrumpyWindow += customers[i];
            }
        }
        for (int i = 0; i<minutes; i++){
            currentSum += customers[i];
        }
        currentSum = currentSum + notGrumpy - notGrumpyWindow;
        int maxSum = currentSum;
        int i = 1;
        int j = minutes;
        while(j<customers.size()){
            if (grumpy[j]==1){
                if (grumpy[i-1]==0){
                    currentSum = currentSum + customers[j];
                }
                else{
                    currentSum = currentSum + customers[j] - customers[i-1];
                }
            }
            else{
                if (grumpy[i-1]==0){
                    currentSum = currentSum;
                }
                else{
                    currentSum = currentSum - customers[i-1];
                }
            }
            if (maxSum<currentSum){
                maxSum = currentSum;
            }
            i++;
            j++;
        }
        return maxSum;
    }
};