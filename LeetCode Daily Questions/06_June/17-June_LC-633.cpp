// https://leetcode.com/problems/sum-of-square-numbers/?envType=daily-question&envId=2024-06-18

class Solution {
public:
    bool isPerfectSquare(int n){
        int root = sqrt(n);
        if (root*root == n){
            return true;
        }
        else{
            return false;
        }
    }
    bool judgeSquareSum(int c) {
        int x = 0;
        int y = c; 
        while(x<=y){
            if (isPerfectSquare(x) && isPerfectSquare(y)){
                return true;
            }
            else if(!isPerfectSquare(y)){
                y = (int)sqrt(y)*sqrt(y);
                x = c-y;
            }
            else{
                x = (int)(sqrt(x)+1)*(sqrt(x)+1);
                y = c-x;
            }
        }
        return false;
    }
};