class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur_sum = 0;
        int gb_sum = INT_MIN;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            cur_sum += nums[i];
            if(cur_sum < nums[i]){
                cur_sum  = nums[i];
            }
            gb_sum = max(gb_sum,cur_sum);
        }
        return gb_sum;
    }
};
