class Solution {
public:
    vector<vector<int>> ans;
    
    void dfs(vector<int> &temp, int n, unordered_map<int, int> &mp){
        if(temp.size()==n){
            ans.push_back(temp);
            return ;
        }
        
        auto it = mp.begin();
        while(it!=mp.end()){
            if(it->second>0){
                temp.push_back(it->first);
                it->second-=1;
                dfs(temp, n, mp);
                it->second+=1;
                temp.pop_back();
            }
            it++;
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp;
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        dfs(temp, n, mp);
        return ans;
    }
};