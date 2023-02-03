class Solution {
public:
    vector<int> dp;
    int rec(int i, vector<int> &nums, bool flag){
        if(i==nums.size()-1 && flag) return 0;
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        
        dp[i]=max(nums[i]+rec(i+2, nums, flag), rec(i+1, nums, flag));
        return dp[i];
    }    

    int rob(vector<int>& nums) {
        // dp.resize(nums.size()+1);
        if(nums.size()==1) return nums[0];
        dp.assign(nums.size()+1, -1);
        int ans=-1;
        rec(0, nums, true);
        int x = dp[0];
        dp.clear();
        dp.assign(nums.size()+1, -1);
        rec(1, nums, false);
        int y = dp[1];
        return max(x, y);
    }
};