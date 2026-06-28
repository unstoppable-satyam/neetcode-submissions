class Solution {
public:
    int countSubstrings(string s) {
        // dp[i][j] = (dp[i+1][j-1]) &&(s[i] == s[j]); 
        // dp[i][i] = 1;
        // dp[i][j] = dp[i+1][j]. dp[i][j-1]
        // s = ab   

        //s = aa
        // if(s[i] == s[i+1]). dp[i][i+1] = true;
        //s = aba
        //dp[i][i] = 1;
        // dp[0][2] = dp[1][1] + (s[0] == s[2]);
        //s = baab
        // dp[0][3] = dp[1][2] 

        int n = s.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
        for(int i = 0; i<n; i++){
            dp[i][i] = 1;
            if( (i <n-1) && (s[i] == s[i+1] ) ) dp[i][i+1] = 1;
        }
        for(int i = n-1; i>=0; i--){
            for(int j = i+2; j<n; j++){
                dp[i][j] = (dp[i+1][j-1] &&(s[i]==s[j]));
            }
        }
        int cnt = 0 ;
        for(int i =0; i<n; i++){
            for(int j=i; j<n; j++){
                if(dp[i][j]) cnt++;
            }
        }
        return cnt;
    }
};
