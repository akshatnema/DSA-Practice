//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> ans;
    void recSum(vector<int> &arr, int i, int sum) {
        if(i==arr.size()) {
            ans.push_back(sum);
            return ;
        }
        
        recSum(arr, i+1, sum);
        recSum(arr, i+1, sum+arr[i]);
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        int sum=0;
        recSum(arr, 0, sum);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends