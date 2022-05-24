// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
	
	public:
	vector<int> downwardDigonal(int n, vector<vector<int>> A)
	{
		int m=A[0].size();
		vector<int> ans;
		for(int i=0;i<n;i++){
		    int j=0;
		    int k=i;
		    while(k>=0){
		        ans.push_back(A[j][k]);
		        j++;
		        k--;
		    }
		}
		for(int j=1;j<n;j++){
		    int i=n-1;
		    int k=j;
		    while(k<n){
		        ans.push_back(A[k][i]);
		        i--;
		        k++;
		    }
		}
		return ans;
	}
};

// { Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}
  // } Driver Code Ends