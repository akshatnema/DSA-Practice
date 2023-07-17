class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> row, col;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(!matrix[i][j]){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(row.count(i) || col.count(j))
                    matrix[i][j] = 0;
            }
        }
        return ;
    }
};