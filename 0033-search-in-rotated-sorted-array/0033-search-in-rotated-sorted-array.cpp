class Solution {
public:
    int binary(vector<int>& nums, int l,int r, int target){
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                r=mid-1;
            else 
                l=mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
      int n=nums.size(); 
        int in=-1;
       if(nums[0]<nums[n-1]){
           in=n-1;
       }
        else{
            int l=0,r=n-1;
            if(l==r) in=l;
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
        
        if(target==nums[in])
            return in;
        else if(target>nums[n-1])
            return binary(nums,0,in,target);
        else 
            return binary(nums,(in+1)%n,n-1,target);
    }
};