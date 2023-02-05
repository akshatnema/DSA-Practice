class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int ans=0, j=0;
        long int pro=1;
        for(int i=0;i<nums.size();i++){
            pro = pro*nums[i];
            while(pro>=k){
                pro=pro/nums[j];
                j++;
            }
            ans+=i-j+1;
        }
        return ans;
    }
};