class Solution {
public:
    
    set<vector<int>> s;
    void dfs(vector<int> &candidates, vector<int> temp, int sum, int target){
        if(sum==target){
            sort(temp.begin(), temp.end());
            s.insert(temp);
            return ;
        }
        if(sum>target) return ;
        
        for(int i=0;i<candidates.size();i++){
            sum+=candidates[i];
            temp.push_back(candidates[i]);
            dfs(candidates, temp, sum, target);
            sum-=candidates[i];
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        int sum=0;
        dfs(candidates, temp, sum, target);
        auto it = s.begin();
        while(it!=s.end()){
            ans.push_back(*it);
            it++;
        }
        return ans;
    }
};