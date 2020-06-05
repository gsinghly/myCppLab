// Time:  O(n)
// Space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for(int i = 1 ; i < prices.size(); i++){
            int diff = prices[i] - prices[i-1];
            ans += (diff > 0 ? diff : 0);
        }
        return ans;
    }
};
