// https://leetcode.com/problems/furthest-building-you-can-reach/description/?envType=daily-question&envId=2024-02-17

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int>pq;
        int bricksUsed = 0;
        int i = 0;
        for (; i<heights.size()-1; i++){
            if (heights[i]>=heights[i+1]){
                continue;
            }
            int heightDiff = heights[i+1] - heights[i];
            if (heightDiff + bricksUsed <= bricks){
                //do we have enough bricks
                bricksUsed += heightDiff;
                pq.push(heightDiff);
            }
            else if (ladders>0){
                if (!pq.empty() && pq.top() > heightDiff){
                    bricksUsed = bricksUsed - pq.top() + heightDiff;
                    pq.pop();
                    pq.push(heightDiff);
                }
                ladders--;
            }
            else{
                break;
            }
        }
        return i;
    }
};