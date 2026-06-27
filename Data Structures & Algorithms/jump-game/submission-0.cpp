class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int start = nums[0];
        for(int i = 1; i<n;i++){
            if(start < i ){
                return false;
            }
            start = max( start , i+nums[i]);
        }
        return true;
    }
};
