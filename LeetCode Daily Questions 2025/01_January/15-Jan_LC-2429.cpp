// https://leetcode.com/problems/minimize-xor/description/?envType=daily-question&envId=2025-01-15

class Solution {
public:
    bool isSet(int x, int bit){
        return x & (1<<bit);
    }
    void setBit(int& x, int bit){
        x |= (1<<bit);
    }
    void unsetBit(int& x, int bit){
        x &= ~(1 << bit);
    }
    int minimizeXor(int num1, int num2) {
        int result = num1;

        int totalCount = __builtin_popcount(num2);
        int count = __builtin_popcount(result);

        int currBit = 0;

        while(count<totalCount){
            if (!isSet(result, currBit)){
                setBit(result, currBit);
                count++;
            }
            currBit++;
        }

        while(count > totalCount){
            if (isSet(result, currBit)){
                unsetBit(result, currBit);
                count--;
            }
            currBit++;
        }
        return result;
    }
};

