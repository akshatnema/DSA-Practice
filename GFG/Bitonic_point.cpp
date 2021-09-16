// This is the question of binary search

// Question link - https://practice.geeksforgeeks.org/problems/maximum-value-in-a-bitonic-array3001/1


#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
    
public:
	
	int findPeakUtil(int arr[], int low,
                 int high, int n)
{
    // Find index of middle element
    // (low + high)/2
    int mid = low + (high - low) / 2;

    // Compare middle element with its
    // neighbours (if neighbours exist)
    if ((mid == 0 || arr[mid - 1] <= arr[mid]) && 
        (mid == n - 1 || arr[mid + 1] <= arr[mid]))
        return mid;

    // If middle element is not peak and its
    // left neighbour is greater than it,
    // then left half must have a peak element
    else if (mid > 0 && arr[mid - 1] > arr[mid])
        return findPeakUtil(arr, low, (mid - 1), n);

    // If middle element is not peak and its
    // right neighbour is greater than it,
    // then right half must have a peak element
    else
        return findPeakUtil(
            arr, (mid + 1), high, n);
}
	
	int findMaximum(int arr[], int n) {
	    
	    return arr[findPeakUtil(arr,0,n-1,n)];
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends