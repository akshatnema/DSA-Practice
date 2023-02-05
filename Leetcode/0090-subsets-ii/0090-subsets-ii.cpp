class Solution {
public:
    set<vector<int>> s;
    void rec(int i, vector<int> &nums, vector<int> &temp){
        if(i==nums.size()){
            s.insert(temp);
            return ;
        }
        rec(i+1, nums, temp);
        temp.push_back(nums[i]);
        rec(i+1, nums, temp);
        temp.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        rec(0, nums, temp);
        auto it = s.begin();
        while(it!=s.end()){
            ans.push_back(*it);
            it++;
        }
        return ans;
    }
};