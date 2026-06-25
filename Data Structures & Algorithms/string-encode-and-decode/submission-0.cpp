class Solution {
public:

    string encode(vector<string>& strs) {
        int n = strs.size();
        string s="";
        for(int i= 0; i<n; i++){
            int sz = strs[i].size();
            string temp = to_string(sz);
            temp += '_';
            s += temp;
            s += strs[i];
        }

        return s;
    }

    vector<string> decode(string s) {
        vector<string> ret;
        string temp;
        int i = 0;
        int n = s.size();
        while(i < n ){
            int j = i;
            string sz = "";
            while(j<n && s[j] != '_' ){
                sz += s[j];
                j++;
            }
            j++;
            int size_of_string = stoi(sz);

            string cur = "";
            int cnt = 0;
            while( cnt< size_of_string){
                cur += s[j+cnt];
                cnt++;
            }
            ret.push_back(cur);
            i = j+cnt;
        }
        return ret;
    }
};
