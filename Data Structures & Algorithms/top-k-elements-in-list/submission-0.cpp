class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mp;
        for(int i =0; i<n; i++){
            mp[nums[i]]++;
        }

        vector<pair<int,int>> v;
        for(auto it: mp){
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end());
        int m = v.size();
        vector<int> ret;
        int cnt =0;
        for(int i =m-1; i>=0; i--){
            ret.push_back(v[i].second);
            cnt++;
            if(cnt == k) break;
        }
        return ret;
    }
};
