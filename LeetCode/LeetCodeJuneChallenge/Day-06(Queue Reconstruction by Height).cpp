// Time : O(n^2)
// Space : O(n)

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        auto comp = [](vector <int> &a, vector <int> &b){
            return (a[0] < b[0]) || ((a[0] == b[0]) && (a[1] > b[1]));
        };
        sort(people.begin(), people.end(), comp);
        vector < vector <int> > ans;
        for(int i = people.size() - 1; i >= 0; i--){
            ans.insert(ans.begin() + people[i][1], people[i]);
        }
        return ans;
    }
};
