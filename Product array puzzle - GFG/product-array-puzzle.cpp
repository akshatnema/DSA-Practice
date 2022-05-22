// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       vector<long long int> pre1(n);
       vector<long long int> pre2(n);
       pre1[0]=nums[0];
       for(int i=1;i<n;i++)
        pre1[i]=pre1[i-1]*nums[i];
       pre2[n-1]=nums[n-1];
       for(int i=n-2;i>=0;i--){
           pre2[i]=pre2[i+1]*nums[i];
       }
       vector<long long int> ans;
       for(int i=0;i<n;i++){
           long long int x=1,y=1;
           if(i-1>=0) x=x*pre1[i-1];
           if(i+1<n) y=y*pre2[i+1];
           ans.push_back(x*y);
       }
       return ans;
    }
};


// { Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends