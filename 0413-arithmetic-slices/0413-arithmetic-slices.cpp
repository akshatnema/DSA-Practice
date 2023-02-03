class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3) return 0;
        int n=nums.size();
        int ans=0, count=0, diff=1e4;
        for(int i=1;i<n-1;i++){
            if(2*nums[i]==nums[i-1]+nums[i+1]){
                if(diff==nums[i+1]-nums[i]){
                    count++;
                    ans+=count;
                }else{
                    if(diff==1e4){
                        count=1;
                        diff=nums[i]-nums[i-1];
                        ans+=1;
                    }else{
                        diff=1e4;
                        count=0;
                        continue;
                    }
                }
            }else{
                diff=1e4;
            }
        }
        return ans;
    }
};