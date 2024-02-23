// https://leetcode.com/problems/insert-delete-getrandom-o1/description/

class RandomizedSet {
public:
    unordered_map<int,int> hash;
    vector<int> elements;
    RandomizedSet() {
        hash={};
        elements={};                
    }
    
    bool insert(int val) {
        if (hash.find(val)==hash.end()){
            hash[val] = elements.size();
            elements.push_back(val);
            return true;
        }
        return false;      
    }
    
    bool remove(int val) {
        if (hash.find(val)==hash.end()){
            return false;
        }
        else{
            int index=hash[val];
            elements[index]=elements.back();
            hash[elements.back()]=index;
            elements.pop_back();            
            hash.erase(val);
        }
        return true;        
    }
    
    int getRandom() {
        int randind=rand()%elements.size();
        return elements[randind];        
    }
};