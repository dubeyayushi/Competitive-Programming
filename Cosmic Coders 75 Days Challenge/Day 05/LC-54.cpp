// https://leetcode.com/problems/spiral-matrix/description/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> v;
        int maxr = m-1, minr = 0, maxc = n-1, minc = 0;

        while(minr<=maxr && minc<=maxc){
            for (int i = minc; i<=maxc; i++){
                v.push_back(matrix[minr][i]);
            }
            minr++;
            if (minr>maxr || minc>maxc){
            break;
            }
            for (int i = minr; i<=maxr; i++){
                v.push_back(matrix[i][maxc]);
            }
            maxc--;
            if (minr>maxr || minc>maxc){
            break;
            }
            for(int i = maxc; i>=minc; i--){
                v.push_back(matrix[maxr][i]);
            }
            maxr--;
            if (minr>maxr || minc>maxc){
            break;
            }
            for (int i = maxr; i>=minr; i--){
                v.push_back(matrix[i][minc]);
            }
            minc++;
        }
        return v;

    }
};