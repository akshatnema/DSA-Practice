// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
  long long int merge(long long arr[], long long temp[], long long l, long long r, long long mid){
      long long int inv_count=0;
      long long i=l, j=mid, k=l;
      while(i<mid && j<=r){
          if(arr[i]<=arr[j]){
              temp[k++]=arr[i++];
          }else{
              temp[k++]=arr[j++];
              inv_count+=mid-i;
          }
      }
      while(i<mid){
          temp[k++]=arr[i++];
      }
      while(j<=r){
          temp[k++]=arr[j++];
      }
      for (i = l; i <= r; i++)
        arr[i] = temp[i];
      return inv_count;
  }
  
    long long int mergeSort(long long arr[],long long temp[], long long l, long long r){
        long long int inv_count=0;
        if(l<r){
            long long mid=(l+r)/2;
            inv_count+=mergeSort(arr,temp,mid+1,r);
            inv_count+=mergeSort(arr,temp,l,mid);
            
            inv_count+=merge(arr,temp,l,r,mid+1);
        }
        return inv_count;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        long long temp[N];
        long long int ans=mergeSort(arr,temp,0,N-1);
        return ans;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends