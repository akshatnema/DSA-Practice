class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
         int ele1=nums[0], ele2=INT_MIN, ct1=1, ct2=0;
        for(int i=1;i<nums.size();i++) {
            if(ct1==0 && nums[i]!=ele2) {
                ele1=nums[i];
                ct1=1;
            } else if(ct2==0 && nums[i]!=ele1) {
                ele2=nums[i];
                ct2=1;
            } else if(nums[i]==ele1) ct1++;
            else if(nums[i]==ele2) ct2++;
            else {
                ct1--;
                ct2--;
            }
        }
        vector<int> ans;
        int count1=0, count2=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==ele1) count1++;
            if(nums[i]==ele2) count2++;
        }
        int n=nums.size();
        if(count1>n/3) ans.push_back(ele1);
        if(count2>n/3) ans.push_back(ele2);
        return ans;
    }
};