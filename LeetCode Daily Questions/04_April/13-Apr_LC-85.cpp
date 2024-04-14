// https://leetcode.com/problems/maximal-rectangle/description/?envType=daily-question&envId=2024-04-13

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        int maxArea = 0;

        //creating a heights vector storing the heights of the rectangles
        vector<int>heights(cols+1, 0);
        
        for (int i = 0; i<rows; i++){
            for (int j = 0; j<cols; j++){
                if (matrix[i][j]=='1'){
                    heights[j]++;
                }
                else{
                    heights[j] = 0;
                }
            }
            // calculating max-area
            stack<int>st;
            for (int j = 0; j<heights.size(); j++){
                while(!st.empty() && heights[j] < heights[st.top()]){
                    int h = heights[st.top()];
                    st.pop();
                    int w = st.empty() ? j : j-st.top() - 1;
                    maxArea = max(maxArea, h*w);
                }
                st.push(j);
            }
        }
        return maxArea;
    }
};