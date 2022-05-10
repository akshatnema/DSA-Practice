class Solution {
public:
    int findMin(vector<int>& nums) {
       int n=nums.size(); 
        int in=-1;
       if(nums[0]<nums[n-1]){
           in=n-1;
       }
        else{
            int l=0,r=n-1;
            while(l<r){
                int i=(l+r)/2;
                if(in!=-1)
                    break;
                if(i+1<n && i>0 && nums[i-1]<nums[i] && nums[i]>nums[i+1]){
                    in=i;
                    break;
                }
                if(i==n-1 || i==0){
                    in=i;
                    break;
                }
                
                    if(nums[i]<nums[0])
                        r=i;
                    else if(nums[i]>nums[n-1])
                        l=i;
                    else in=i;
                
            }
        }
        int ansi=(in+1)%n;
        return nums[ansi];
    }
};