class Solution {
public:
    int solve(int i, vector<int> &dp){
        if( i <= 1 ) return dp[i] = 1;
        if(dp[i] != -1 ) return dp[i];
        int op1 = solve(i-1,dp);
        int op2 = solve(i-2,dp);
        return dp[i] = op1+op2;
    }

    int climbStairs(int n) {
        if( n <= 1 ) return 1;
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};
