class Solution {
public:
    set<vector<int>> ans;
    
    void dfs(int i, vector <int>& nums, vector <int>& temp){
        if(i==nums.size()){
            if(temp.size()>=2) ans.insert(temp);
            return ;
        }
        
        if(temp.size()>0){
        if(temp[temp.size()-1]<=nums[i]){
            temp.push_back(nums[i]);
            dfs(i+1, nums, temp);
            temp.pop_back();
        }}else{
            temp.push_back(nums[i]);
            dfs(i+1, nums, temp);
            temp.pop_back();
        }
        dfs(i+1, nums, temp);
        return ;
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        dfs(0, nums, temp);
        return vector(ans.begin(), ans.end());
    }
};