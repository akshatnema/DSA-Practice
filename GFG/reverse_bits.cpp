// Question link - https://practice.geeksforgeeks.org/problems/reverse-bits-1611130171/1/

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    unsigned int reverseBits(unsigned int n)
    {
        unsigned int x=0;
        string s;
        while(n!=0)
        {
            if(n & 1)
             {
                s+='1'; 
             }
            else
             s+='0';
           n=n>>1;
        }
        int i=s.size()-1;
        while(i>=0)
        {
            int y=s[i]-'0';
            if(y==1)
            {
                x=x+pow(2,s.size()-i-1);
            }
            i--;
        }
        return x;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout<< ob.reverseBits(N) <<"\n";
        
    }
    return 0;
}
  // } Driver Code Ends