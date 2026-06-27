class Solution {
public:
    

    string longestPalindrome(string s) {
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
        for(int i = 0; i<n ; i++){
            if(p[i] == mx_len) {
                centre = i;
            }
        }
        int st = (centre - mx_len)/2;
        return s.substr(st,mx_len);
    }
};
