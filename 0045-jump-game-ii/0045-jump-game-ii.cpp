class Solution {
public:
    vector<int>dp;
    int rec(int i, vector <int>& nums){
        if(nums.size()-1==i) return 0;
        
        if(dp[i]!=(int)1e4) return dp[i];
        
        for(int j=1;j<=nums[i];j++){
            if(i+j<nums.size()){
                dp[i] = min(dp[i], 1+rec(i+j, nums));
            }
        }
        return dp[i];
    }
    
    int jump(vector<int>& nums) {
        dp.assign(nums.size()+1, 1e4);
        dp[0]=rec(0, nums);
        return dp[0];
    }
};