class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        map < int, int > e;
        for(int i = 0; i < a.size(); i++){
            if(e.find(target - a[i]) != e.end())  return {e[target-a[i]], i};
            e[a[i]] = i;
        }
        return {};
    }
};