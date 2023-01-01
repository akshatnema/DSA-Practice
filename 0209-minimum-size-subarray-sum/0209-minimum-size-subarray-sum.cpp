class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(target==0) return 0;
        int mi=1e9, left=0, sum=0, flag=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            while(sum>=target){
                flag=0;
                mi=min(mi, i-left+1);
                sum-=nums[left];
                left++;
            }
        }
        if(flag) return 0;
        return mi;
    }
};