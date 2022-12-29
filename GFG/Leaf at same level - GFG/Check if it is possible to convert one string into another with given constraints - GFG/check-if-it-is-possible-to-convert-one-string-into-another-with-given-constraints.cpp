//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isItPossible(string S, string T, int M, int N) {
        int flag=0, ctA=0, ctB=0;
        for(int i=0;i<S.length();i++){
            if(T[i]=='A') ctA++;
            if(S[i]=='A'){
                if(ctA>0) ctA--;
                else return 0;
            }
            if(S[i]=='B'){
                if(ctA>0) return 0;
                ctB++;
            }
            if(T[i]=='B'){
                if(ctB>0) ctB--;
                else return 0;
            }
        }
        ctA=0, ctB=0;
        for(int i=S.length()-1;i>=0;i--){
            if(T[i]=='B') ctB++;
            if(S[i]=='B'){
                if(ctB>0) ctB--;
                else return 0;
            }
            if(S[i]=='A'){
                if(ctB>0) return 0;
                ctA++;
            }
            if(T[i]=='A'){
                if(ctA>0) ctA--;
                else return 0;
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, T;
        cin >> S >> T;
        int M = S.length(), N = T.length();
        Solution ob;
        cout << ob.isItPossible(S, T, M, N);
        cout << "\n";
    }
}
// } Driver Code Ends