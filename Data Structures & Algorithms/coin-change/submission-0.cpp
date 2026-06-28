class Solution {
public:
    int solve(int amount,vector<int> &coins,vector<int> &dp){
        if(amount < 0 ) return 10000;
        if(amount == 0 ) return dp[amount] = 0;
        if(dp[amount] != - 1) return dp[amount];
        int op1 = INT_MAX;
        for(int i = 0; i<coins.size(); i++){
            op1 = min(op1, 1+ solve(amount - coins[i], coins,dp));
        }
        return dp[amount] = op1;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp( amount+1, -1 );
        int ans = solve( amount,coins,dp);
        return (ans >= 10000 ? -1 : ans);
    }
};
