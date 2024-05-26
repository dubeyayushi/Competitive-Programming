// https://leetcode.com/problems/student-attendance-record-ii/description/

#define MOD 1000000007
class Solution {
public:
    int dp[100005][2][3]; //stores n, total_absences, consecutive_late

    int eligible_combinations(int n, int total_absences, int consecutive_lates){
        if (total_absences>=2 || consecutive_lates>=3) return 0;
        if (n==0) return 1;
        if (dp[n][total_absences][consecutive_lates]!=-1) return dp[n][total_absences][consecutive_lates];

        int count = 0;
        // for P
        count = eligible_combinations(n-1, total_absences, 0);
        // for A
        count = (count + eligible_combinations(n-1, total_absences+1, 0)) % MOD;
        // for L
        count = (count + eligible_combinations(n-1, total_absences, consecutive_lates+1)) % MOD;

        return dp[n][total_absences][consecutive_lates] = count;
    }

    int checkRecord(int n) {
        memset(dp, -1, sizeof(dp));
        return eligible_combinations(n, 0, 0);
    }
};