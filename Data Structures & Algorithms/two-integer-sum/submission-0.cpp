class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            int val = target - nums[i];
            if(mp.find(val) != mp.end() ){
                int ind = mp[val] - 1;
                return {ind,i};
            }
            mp[nums[i]] = i+1;
        }
        return {0,1};
    }
};
