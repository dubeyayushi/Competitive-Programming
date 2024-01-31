//https://leetcode.com/problems/insert-delete-getrandom-o1/description/?envType=daily-question&envId=2024-01-16

class RandomizedSet {
public:
    unordered_set<int>s;
    vector<int>v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (s.find(val)!=s.end()){
            return false;
        }
        s.insert(val);
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (s.find(val)!=s.end()){
            s.erase(val);
            auto ele = find(v.begin(), v.end(), val);
            v.erase(ele);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int randIdx = rand() % v.size();
        return v[randIdx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */