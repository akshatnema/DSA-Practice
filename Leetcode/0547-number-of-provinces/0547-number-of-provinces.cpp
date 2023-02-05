class Solution {
public:
    unordered_map <int,vector<int>> mp;
    int findCircleNum(vector<vector<int>>& isConnected) {
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(i==j) continue;
                if(isConnected[i][j]==1){
                  mp[i].push_back(j);
                mp[j].push_back(i);    
                }
                
            }
        }
        int n=isConnected.size();
        int ans=0;
        vector<int> vis(isConnected.size(),0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i,vis);
            }
        }
        return ans;
    }
    
    void dfs(int i, vector<int> &vis){
        if(i>=vis.size() || vis[i]==1)
            return ;
        vis[i]=1;
        for(int j=0;j<mp[i].size();j++){
            if(!vis[mp[i][j]])
                dfs(mp[i][j],vis);
        }
        return ;
    }
};