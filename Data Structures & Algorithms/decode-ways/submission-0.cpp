class Solution {
public:
    // {0} , > 26  problem
    // {3 .nothing.}
    // {1 . something}
    // {.something. 0 }
    //  either one digit or 2 digit

    int solve(int i ,int n,string &s, vector<int> &dp){
        if(i >= n ) return 1;
        if(i == n-1){
            return dp[i] =((s[i]-'0') > 0 );
        }
        if(dp[i] != -1 ) return dp[i];
        int op1 = 0, op2 = 0;
        if( (s[i]-'0') >  0 ){
            op1 = solve(i+1,n,s,dp);
        }
        if( (i!= n-1)  && ((s[i]-'0') > 0) ){
            int cur = (s[i]-'0')*10 + (s[i+1]-'0');
            if( cur <= 26 && cur >= 10 ){
                op2 = solve(i+2,n,s,dp);
            }
        }
        return dp[i] = op1+ op2;
    }


    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        return solve(0,n,s,dp);
    }
};
