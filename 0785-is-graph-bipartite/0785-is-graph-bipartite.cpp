class Solution {
public:
    
    bool dfs(vector<vector<int>>& graph, vector<int> &col, int cl, int ind){
        if(col[ind]!=-1 && col[ind]!=cl) return false;
        
        col[ind]=cl;
        for(int i=0;i<graph[ind].size();i++){
            if(col[graph[ind][i]]==-1){
                bool t = dfs(graph, col, cl^1, graph[ind][i]);
                if(!t) return false;
            }else{
                if(col[graph[ind][i]]==cl) return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> col(graph.size(), -1);
        for(int i=0;i<graph.size();i++){
            if(col[i]==-1){
                bool t = dfs(graph, col, 0, i);
                if(!t) return false;
            }
        }
        return true;
    }
};