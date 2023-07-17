class Solution {
public:
    void sortColors(vector<int>& nums) {
       int count0=0, count1=0, count2=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] == 0) count0++;
            else if(nums[i]==1) count1++;
            else count2++;
        }
        vector<int> ans;
        while(count0>0){
            ans.push_back(0);
            count0--;
        }
        while(count1>0){
            ans.push_back(1);
            count1--;
        }
        while(count2>0){
            ans.push_back(2);
            count2--;
        }
        nums = ans;
    }
};