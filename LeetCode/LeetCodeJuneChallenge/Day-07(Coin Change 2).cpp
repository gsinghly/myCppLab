// Time : O(n^2)
// Space : O(n^2) can be optimised to O(n) 
class Solution {
    int dp[501][5001];
public:
    int func(vector < int > coins, int n, int amount){
        if(amount == 0){
            return 1;
        }
        if(amount < 0 || (amount > 0 && n <= 0)){
            return 0;
        }
        if(dp[n][amount] != -1){
            return dp[n][amount];
        }
        return dp[n][amount] = func(coins, n - 1, amount) + func(coins, n, amount-coins[n-1]);

    }
    
    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        return func(coins, coins.size(), amount);
    }
};
