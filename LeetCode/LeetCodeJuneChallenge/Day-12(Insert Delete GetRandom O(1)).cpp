// Time:  O(1)
// Space: O(n)

class RandomizedSet {
private:
    vector < int > v;
    unordered_map <int, int > used;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(used.count(val)){
            return false;
        }
        v.emplace_back(val);
        used[val] = v.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!used.count(val)){
            return false;
        }
        used[v.back()] = used[val];
        swap(v[used[val]], v.back());
        used.erase(val);
        v.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int n = (int)v.size();
        int ans = v[rand() % n];   
        return ans;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
