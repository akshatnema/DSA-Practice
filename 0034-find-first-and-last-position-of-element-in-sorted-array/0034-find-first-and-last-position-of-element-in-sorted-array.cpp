class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       if(nums.size()==0){
           vector<int> v;
           v.push_back(-1);
           v.push_back(-1);
           return v;
       } 
       int l=0,r=nums.size()-1;
        int mi=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target){
                if(mid>0){
                    if(nums[mid]==nums[mid-1])
                        r=mid-1;
                    else{
                        mi=mid;
                        break;
                    }
                }
                else{
                    mi=mid;
                    break;
                }
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else 
                r=mid-1;
        }
        int mx=-1;
         l=0,r=nums.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target){
                if(mid<nums.size()-1){
                    if(nums[mid]==nums[mid+1])
                        l=mid+1;
                    else{
                        mx=mid;
                        break;
                    }
                }
                else{
                    mx=mid;
                    break;
                }
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else 
                r=mid-1;
        }
        vector <int> v;
        v.push_back(mi);
        v.push_back(mx);
        return v;
    }
};