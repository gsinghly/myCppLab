// Time : O(n+q*logn), where q = no of queries and pickIndex is O(logn) in time.
// Space: O(n)
class Solution {
    vector <int> v;
public:
    Solution(vector<int>& w) {
        v.push_back(w[0]);
        for(int i = 1; i< w.size(); i++){
            v.push_back(v.back()+w[i]);
        }
    }
    
    int pickIndex() {
        int rand_wt = rand()%(v.back()+1);
        return upper_bound(v.begin(), v.end(), rand_wt)- v.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
