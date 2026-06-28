typedef long long ll;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        ll ans = nums[0];
        ll cur_min = 1;
        ll cur_max= 1;
        
        int n = nums.size();

        for(int i=0;i<n; i++){
            ll temp = cur_max*nums[i];
            cur_max = max( {temp, nums[i]*cur_min, 1LL*nums[i] } );
            cur_min = min( {temp, nums[i]*cur_min, 1LL*nums[i] } );
            ans = max(ans,cur_max);
        }
        return ans;
    }
};
