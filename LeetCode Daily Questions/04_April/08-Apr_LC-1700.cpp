// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/?envType=daily-question&envId=2024-04-08

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>q;
        int n = students.size();
        for (int i = 0; i<n; i++){
            q.push(students[i]);
        }
        int i = 0;
        while(i<n){
            int count = 0;
            if (q.front()==sandwiches[i]){
                q.pop();
                i++;
            }
            else{   
                while(q.front()!=sandwiches[i]){
                    if (count!=q.size()){
                        int temp = q.front();
                        q.pop();
                        q.push(temp);
                        count++;
                    }
                    else{
                        break;
                    }
                }
                if (count!=q.size()){
                    count = 0;
                }
            }
            if (count == q.size()){
                return q.size();
            }
        }
        return 0;
    }
};