class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int pr = 1;
        int cnt_z = 0;
        for(int i =0;i<n; i++){
            if(nums[i] == 0) cnt_z++;
            else pr= pr*nums[i];
        }
        vector<int> ret(n,0);
        if(cnt_z > 1){
            return ret;
        } 
        else if(cnt_z == 1 ){
            for(int i= 0; i<n;i++){
                if(nums[i] == 0 ){
                    ret[i] = pr;
                }
            }
            return ret;
        }
        else{
            for(int i= 0; i<n;i++){
                ret[i] = pr/nums[i];
            }
            return ret;
        }
    }
};
