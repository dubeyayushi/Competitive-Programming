// https://leetcode.com/problems/range-frequency-queries/description/

class RangeFreqQuery {
public:
    vector<unordered_map<int, int>>st;
    int n;
    RangeFreqQuery(vector<int>& arr) {
        n = arr.size();
        st.resize(4*n);
        buildTree(arr, 0, 0, n-1);
    }
    
    void buildTree(vector<int>&arr, int i, int lo, int hi){
        if (lo==hi){
            st[i][arr[lo]]++;
            return;
        }
        int mid = lo + (hi-lo)/2;
        buildTree(arr, 2*i+1, lo, mid);
        buildTree(arr, 2*i+2, mid+1, hi);
        st[i] = mapUnion(st[2*i+1], st[2*i+2]);
    }

    unordered_map<int, int> mapUnion(unordered_map<int, int>&mp1, unordered_map<int, int>&mp2){
        unordered_map<int, int>mp;
        for (auto ele : mp1){
            mp[ele.first] = ele.second;
        }
        for (auto ele : mp2){
            if (mp.find(ele.first)!=mp.end()){
                mp[ele.first] += ele.second;
            }
            else{
                mp[ele.first] = ele.second;
            }
        }
        return mp;
    }

    int getFreq(int i, int lo, int hi, int& left, int& right, int& value){
        if (right<lo || left>hi) return 0;
        if (lo>=left && hi<=right){
            if (st[i].find(value)==st[i].end()) return 0;
            else return st[i][value];
        } 
        int mid = lo + (hi-lo)/2;
        return getFreq(2*i+1, lo, mid, left, right, value) + getFreq(2*i+2, mid+1, hi, left, right, value);
    }

    int query(int left, int right, int value) {
        return getFreq(0, 0, n-1, left, right, value);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */