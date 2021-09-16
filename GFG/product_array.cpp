// Question link is - https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/1


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
       long long int pro=1,zero=0;
       for(int i=0;i<n;i++)
       {  if(nums[i]!=0)
            pro*=nums[i];
          else
           zero++;
       }
       if(zero>1)
        pro=zero;
        vector <long long int> ans;
        for(int i=0;i<n;i++)
       {  
          if(zero>0)
          {
              if(nums[i]==0 && zero==1)
                ans.push_back(pro);
              else 
                ans.push_back(0);
          }
          else
          {
              long long int x=pro/nums[i];
              ans.push_back(x);
          }
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