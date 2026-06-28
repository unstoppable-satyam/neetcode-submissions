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

        // int n = s.size();
        // vector<vector<int>> dp(n,vector<int> (n,0));
        // for(int i = 0; i<n; i++){
        //     dp[i][i] = 1;
        //     if( (i <n-1) && (s[i] == s[i+1] ) ) dp[i][i+1] = 1;
        // }
        // for(int i = n-1; i>=0; i--){
        //     for(int j = i+2; j<n; j++){
        //         dp[i][j] = (dp[i+1][j-1] &&(s[i]==s[j]));
        //     }
        // }
        // int cnt = 0 ;
        // for(int i =0; i<n; i++){
        //     for(int j=i; j<n; j++){
        //         if(dp[i][j]) cnt++;
        //     }
        // }
        // return cnt;


        string t = "#";
        for(char c: s){
            t += c;
            t += '#';
        }

        int centre = 0,r = 0;
        int n = t.size();
        vector<int> p(n,0);
        int mx_len = 0;
        int start_ind = 0;
        
        for(int i =0; i<n; i++){
            if( i < r ){
                p[i] = min(r-i, p[2*centre-i]);
            }
            while( (i -p[i] - 1 >= 0) &&  (i  + p[i] + 1 <n)  && ( t[i-p[i]-1] == t[i+p[i]+1])  ){
                p[i]++;
            }
            
            if( i + p[i] > r ){
                centre = i;
                r = i+p[i];
            }
            if( p[i] > mx_len){
                mx_len= p[i];
                //centre = i;
            }
        }
        int cnt =0;
        for(int i = 0; i<n ; i++){
            cnt += (p[i]+1)/2;
        }
        
        return cnt;
    }
};
