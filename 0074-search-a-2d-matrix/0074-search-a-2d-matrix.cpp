class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0, j=0, n=matrix.size()-1, m=matrix[0].size()-1;
        while(i<=n){
            int mid = (i+n)/2;
            if(matrix[mid][0]<=target && target<=matrix[mid][m]){
                // cout<<mid<<endl;
                while(j<=m){
                    int mid1=(j+m)/2;
                    if(matrix[mid][mid1]==target) return true;
                    else if(matrix[mid][mid1]<target) j=mid1+1;
                    else m=mid1-1;
                }
                return false;
            }
            else if(matrix[mid][0]>target){
                n=mid-1;
            }else if(matrix[mid][m]<target){
                i=mid+1;
            }else{
             
            }
        }
        return false;
    }
};