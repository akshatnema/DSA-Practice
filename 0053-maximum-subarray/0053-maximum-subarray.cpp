class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0, mx=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            mx=max(sum, mx);
            if(sum<0) sum=0;
        }
        if(!mx) return *max_element(nums.begin(), nums.end());
        return mx;
    }
};