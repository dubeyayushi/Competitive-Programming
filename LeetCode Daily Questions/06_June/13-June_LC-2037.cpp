// https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/description/

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int ans = 0;
        for (int i = 0; i<students.size(); i++){
            ans = ans + abs(students[i] - seats[i]);
        }
        return ans;
    }
};