class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strings) {
        int n = strings.size();

        if(n == 0 ) return {{}};
        vector<pair<string,string>> strs(n);
        for(int i= 0; i<n; i++){
            strs[i] = {strings[i],strings[i]};
        }

        for(int i= 0; i<n; i++){
            sort( strs[i].first.begin(),strs[i].first.end());
        }
        sort(strs.begin(),strs.end());

        vector<vector<string>> ret;
        vector<string> cur;
        cur.push_back(strs[0].second);
        for(int i=1; i<n; i++){
            string last = cur.back();
            sort(last.begin(),last.end());

            // if(last == "" && strs[i].first == ""){
            //     cur.push_back(strs[i].second);
            //     continue;
            // }
            if( strs[i].first == last){
                cur.push_back(strs[i].second);
            }
            else{
                ret.push_back(cur);
                vector<string> temp;
                cur = temp;
                cur.push_back(strs[i].second);
            }
        }
        ret.push_back(cur);
        return ret;
    }
};
