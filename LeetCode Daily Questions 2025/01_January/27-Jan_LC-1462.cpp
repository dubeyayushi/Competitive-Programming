// https://leetcode.com/problems/course-schedule-iv/description/?envType=daily-question&envId=2025-01-27

class Solution {
public:
    void preprocess(int numCourses, vector<vector<int>>& prerequisites, unordered_map<int, vector<int>>&adjList, vector<vector<bool>>& isPrerequisite){
        for (int i = 0; i<numCourses; i++){
            queue<int>q;
            q.push(i);

            while(!q.empty()){
                int node = q.front();
                q.pop();
                for (auto adj : adjList[node]){
                    if (!isPrerequisite[i][adj]){
                        isPrerequisite[i][adj] = true;
                        q.push(adj);
                    }
                }
            }
        }

    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adjList;

        for (auto prereq : prerequisites){
            adjList[prereq[0]].push_back(prereq[1]);
        }

        vector<vector<bool>>isPrerequisite(numCourses, vector<bool>(numCourses, false));
        preprocess(numCourses, prerequisites, adjList, isPrerequisite);

        vector<bool>ans;
        for (auto q : queries){
            ans.push_back(isPrerequisite[q[0]][q[1]]);
        }
        return ans;
    }
};