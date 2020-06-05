// Time:  O(n*mlogm) where m is the length of longest string in strs
// Space: O(n*d) where d is no of distict sorted strings 
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector < vector < string > > ans;
        map < string,  vector < string > > v;
        for(auto it : strs){
            string a = it;
            sort(a.begin(), a.end());
            v[a].push_back(it);
        }
        
        for(auto it : v){
            vector < string > res;
            for(auto itt : it.second){
                res.push_back(itt);
            }
            ans.push_back(res);
        }
        return ans;
    }
};
