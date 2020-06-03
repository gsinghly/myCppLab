//Approach-1
// Time:  O(nlogn)
// Space: O(1) 
//Priority queues can also be used to keep diff of a & b with idx - Space O(n) ~ {a[0]-a[1], idx};
class Solution {
public:
    static bool comp(vector < int > &a, vector < int > &b){
        return a[0] - a[1] < b[0] - b[1];
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        //auto comp = [](auto a, auto b){           //Lambda functions C++11
        //    return a[0] - a[1] < b[0] - b[1];
        //};
        sort(costs.begin(), costs.end(), comp);
        int ans = 0, n = costs.size();
        for(int i = 0; i < n; i++){
            ans += ((i < n/2) ? costs[i][0]: costs[i][1]);
        }
        return ans;
    }
};

//Approach-2
// Time:  O(nlogn)
// Space: O(n)
class Solution {
public:
    static bool comp(vector < int > &a, vector < int > &b){
        return a[0] - a[1] < b[0] - b[1];
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int ans = 0;
        sort(costs.begin(), costs.end(), comp);
        vector < int > v;
        for(int i = 0; i < costs.size(); i++){
            ans += costs[i][0];
            v.push_back(costs[i][1] - costs[i][0]);
        }
        sort(v.begin(), v.end());
        for(int i =0 ; i < v.size()/2; i++){
            ans += v[i];
        }
        return ans;
    }
};
