//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix){
        //code here
        pair<int,int> ans;
        int i=0, j=0;
        int ic = 0, jc = 1;
        while(i<matrix.size() && j<matrix[i].size()){
            if(matrix[i][j]!=0){
                matrix[i][j]=0;
                if(ic==0 && jc==1){
                    ic = 1;
                    jc = 0;
                }
                else if(ic==1 && jc==0){
                    ic = 0;
                    jc = -1;
                }
                else if(ic==0 && jc==-1){
                    ic = -1;
                    jc = 0;
                }
                else{
                    ic = 0;
                    jc += 1;
                }
            }
            i+=ic;
            j+=jc;
        }
        ans.first = (i-ic);
        ans.second = (j-jc);
        return ans;
    }

};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends