class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0) nums[i]=0;
        }
        for(int i=0;i<nums.size();i++){
            int x=abs(nums[i]);
            if(x>0 && x<=n && nums[x-1]>=0){
                if(nums[x-1]==0) nums[x-1]=-n;
                else nums[x-1]=-nums[x-1];
            }
        }
        for(int i=1;i<=n;i++){
            if(nums[i-1]>=0) return i;
        }
        return n+1;
    }
};