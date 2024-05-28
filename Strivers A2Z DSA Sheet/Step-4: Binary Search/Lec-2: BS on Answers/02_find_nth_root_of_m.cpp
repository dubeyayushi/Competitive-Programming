// https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-nth-root-of-m

class Solution{
    public:
    int NthRoot(int n, int m) {
        // Check edge cases
        if (m == 0) return 0;
        if (m == 1) return 1;

        int low = 1;
        int high = m;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long val = 1;
            for (int i = 0; i < n; i++) {
                val *= mid;
                if (val > m) break;
            }
            if (val == m) return mid;
            else if (val > m) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;  // if there is no integer nth root
    }
};