class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int st =0, en = 0;
        int mx = 1;
        for(int i = 0; i<n; i++){
            int j = i, k = i;
            while( j >= 0 && k <n  && (s[j] == s[k]) ){
                j--;
                k++;
            }
            int sz = k-j-1;
            if(sz > mx ){
                mx = sz;
                st = j+1; en = k-1;
            }
            if(i <n-1 &&  s[i] == s[i+1] ){
                j = i; k = i+1;
                while( j >= 0 && k <n  && (s[j] == s[k]) ){
                    j--;
                    k++;
                }
                sz = k-j-1;
                if(sz > mx ){
                    mx = sz;
                    st = j+1; en = k-1;
                }
            }
        }
        string ans = s.substr(st,en-st+1);
        return ans;
    }
};
