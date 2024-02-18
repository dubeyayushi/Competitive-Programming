// https://leetcode.com/problems/meeting-rooms-iii/description/?envType=daily-question&envId=2024-02-18

#define ll long long int

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {

        sort(meetings.begin(), meetings.end());

        vector<ll>counts(n, 0);  // storing the number of times each room is used
        priority_queue<ll, vector<ll>, greater<ll>>freeRooms;    // storing the free rooms
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>endTimes;    //storing the end times of the meetings along with their room numbers

        //initially all rooms are free
        for (int i = 0; i<n; i++){
            freeRooms.push(i);
        }

        for (int i = 0; i<meetings.size(); i++){

            int start = meetings[i][0];
            int end = meetings[i][1];

            while(!endTimes.empty() && endTimes.top().first <= start){
                freeRooms.push(endTimes.top().second);
                endTimes.pop();
            }
            // while we have free rooms, we keep the meetings in different rooms
            if (!freeRooms.empty()){
                ll curr = freeRooms.top();
                endTimes.push({end, curr});
                freeRooms.pop();
                counts[curr]++;
            }
            // if we do not have any free room left, we wait for the meeting with the lowest end time to get over and occupy its room
            else{
                pair<ll, ll>curr = endTimes.top();
                endTimes.pop();
                endTimes.push({curr.first + (end-start), curr.second});
                counts[curr.second]++;
            }
        }
        ll maxCount = INT_MIN;
        ll ans = 0;
        for(int i = 0; i<counts.size(); i++){
            if (counts[i]>maxCount){
                maxCount = counts[i];
                ans = i;
            }
        }
        return ans;
    }
};