// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
           vector <int> v;
           int l=0,r=0;
           while(l<n && r<m){
               if(arr1[l]<arr2[r]){
                v.push_back(arr1[l]);
                l++;
               }else{
                v.push_back(arr2[r]);
                r++;
               }
           }
           while(l<n){
               v.push_back(arr1[l]);
               l++;
           }
           while(r<m){
               v.push_back(arr2[r]);
               r++;
           }
           int k=0;
           for(int i=0;i<n;i++){
               arr1[i]=v[k];
               k++;
           }
           for(int j=0;j<m;j++){
               arr2[j]=v[k];
               k++;
           }
        } 
};

// { Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 
  // } Driver Code Ends