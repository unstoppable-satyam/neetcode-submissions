class Solution {
public:

    int solve(int i, int first_taken,vector<int> &nums,vector<vector<int>> &dp ,int n){
        if(i >= n ) return 0;
        if(i == n-1){
            if(first_taken){
                return dp[i][first_taken] = 0;
            }
            else{
                return dp[i][first_taken] = nums[i];
            }
        }
        if(dp[i][first_taken] != -1)  return dp[i][first_taken];

        if(i == 0 ){
            if(first_taken ){
                return dp[i][first_taken] = nums[i] + solve(i+2,1,nums,dp,n);
            }
            else{
                return dp[i][first_taken] = solve(i+1,0,nums,dp,n);
            }
        }
        else{   
            int op1 = nums[i] + solve(i+2,(first_taken|0), nums,dp,n);
            int op2 = solve(i+1 , (first_taken|0), nums,dp,n);
            return dp[i][first_taken] = max(op1,op2);
        }
        
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        vector<vector<int>> dp(n,vector<int> (2,-1));
        return max(solve(0,0,nums,dp,n), solve(0,1,nums,dp,n));
    }
};
