class Solution {
public:
    void rec(int i, vector<int> &nums, vector<int> temp, vector<vector<int>> &ans){
        if(i==nums.size()){
            ans.push_back(temp);
            return ;
        }
        rec(i+1, nums, temp, ans);
        temp.push_back(nums[i]);
        rec(i+1, nums, temp, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        rec(0, nums, temp, ans);
        return ans;
    }
};