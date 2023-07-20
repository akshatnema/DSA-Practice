class Solution {
public:
    vector<vector<int>> ans;
    void rec(vector<int>& nums, vector<int> &temp, int k, int sum, int i) {
        if(sum==k) {
            ans.push_back(temp);
            return ;
        }
        if(sum>k || i>=nums.size()) return ;
        // for(int j=0;j<temp.size();j++) {
        //     cout<<temp[j]<<" ";
        // }
        // cout<<endl;
        if(sum+nums[i]<=k) {
            temp.push_back(nums[i]);
            rec(nums, temp, k, sum+nums[i], i);
            temp.pop_back();
            rec(nums, temp, k, sum, i+1);
        } else 
            return ;
    }
    
    vector<vector<int> > combinationSum(vector<int>& nums,int k){
       sort(nums.begin(), nums.end());
        vector<int> temp;
        rec(nums, temp, k, 0, 0);
        return ans;
    }
};