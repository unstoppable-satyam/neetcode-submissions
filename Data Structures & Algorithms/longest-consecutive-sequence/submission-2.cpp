class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 ) return 0;

        map<int,int> mp;
        int mx = 1;
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }

        int last_ele = INT_MIN;
        int last_freq = 1;
        for(auto it :mp){
            cout<<it.first<<" ";
            int cur_ele = it.first;
            if( cur_ele == (last_ele+1) ){
                last_ele = cur_ele;
                last_freq++;
            }
            else{
                last_ele = cur_ele;
                last_freq = 1;
            }
            mx = max(mx,last_freq);
        }
        return mx;
    }
};
