class Solution {
public:
    vector<int> dp;
    bool rec(int i, vector<int> &nums){
        if(i==nums.size()-1) return true;
        if(i>=nums.size()) return false;
        if(dp[i]!=-1) return dp[i];            

        for(int j=1;j<=nums[i];j++){
            bool temp = rec(i+j, nums);
            if(temp){
                dp[i]=1;
                break;
            }
        }
        if(dp[i]==-1) dp[i]=0;
        return dp[i];
    }
    
    bool canJump(vector<int>& nums) {
        dp.assign(nums.size()+1, -1);
        dp[0]=rec(0, nums);
        return dp[0];
    }
};