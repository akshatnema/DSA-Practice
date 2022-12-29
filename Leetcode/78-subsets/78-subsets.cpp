class Solution {
public:
    vector<vector<int>> ans;
    void rec(vector<int> &nums, int i, vector <int> arr){
        if(i==nums.size()){
            ans.push_back(arr);
            return ;
        }
        rec(nums, i+1, arr);
        arr.push_back(nums[i]);
        rec(nums, i+1, arr);
        return ;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        rec(nums, 0, temp);
        return ans;
    }
};