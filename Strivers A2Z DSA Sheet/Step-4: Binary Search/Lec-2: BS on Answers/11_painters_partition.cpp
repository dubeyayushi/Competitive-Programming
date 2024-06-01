// https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

bool check(int time, vector<int> &boards, int k){
    int totalTime = 0;
    int painterCount = 1;
    for (int i = 0; i<boards.size(); i++){
        if (totalTime + boards[i] <= time){
            totalTime += boards[i];
        }
        else{
            totalTime = boards[i];
            painterCount++;
        }
        if (painterCount > k) return false;
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int maxlen = -1;
    int sum = 0;
    for (int i = 0; i<boards.size(); i++){
        maxlen = max(maxlen, boards[i]);
        sum += boards[i];
    }
    int start = maxlen;
    int end = sum;
    while(start<=end){
        int mid = start + (end-start)/2;
        if (check(mid, boards, k)){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return start;
}