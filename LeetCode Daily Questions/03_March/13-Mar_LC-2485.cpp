// https://leetcode.com/problems/find-the-pivot-integer/description/?envType=daily-question&envId=2024-02-23

class Solution {
public:
    int pivotInteger(int n) {
        if (n==1) return 1;
        int sumLeft = 1;
        int sumRight = (n*(n+1)/2);
        for (int i = 2; i<=n; i++){
            sumLeft += i;
            sumRight -= (i-1);
            if (sumLeft==sumRight) return i;
        }
        return -1;
    }
};

