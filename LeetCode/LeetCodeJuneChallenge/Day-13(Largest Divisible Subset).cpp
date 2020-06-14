// Time:  O(n*n)
// Space: O(n)

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(!nums.size())    return {};
        int ans = 0, n = nums.size();
        vector < int > dp(n+1, 1), prev(n+1, -1);
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if((nums[i]%nums[j] == 0) && (dp[i] < dp[j]+1)){
                    dp[i] = dp[j]+1;
                    prev[i] = j;
                }
            } 
            if(dp[ans] < dp[i]){
                ans = i;
            }
        }
        vector < int > res;
        for(int i = ans; i >= 0;){
                res.push_back(nums[i]);
                i = prev[i];
        }
        return res;
    }
};
