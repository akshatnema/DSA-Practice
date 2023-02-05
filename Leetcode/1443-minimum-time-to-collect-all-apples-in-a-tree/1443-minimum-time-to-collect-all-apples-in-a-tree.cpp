class Solution {
public:
    int dfs(int i, vector<vector<int>>& edges, vector<bool>& hasApple, vector<bool> &visited){
        visited[i]=true;
        int ans = 0;
        for(int j=0;j<edges[i].size();j++){
            if(!visited[edges[i][j]]){
                int temp = dfs(edges[i][j], edges, hasApple, visited);
                ans+=temp;
            }
        }
        if(ans || hasApple[i]) return (ans+2);
        else return 0;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> edge(n);
        for(int i=0;i<edges.size();i++){
            edge[edges[i][0]].push_back(edges[i][1]);
            edge[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n, false);
        int ans = dfs(0, edge, hasApple, visited);
        if(ans) return ans-2;
        else return 0;
    }
};