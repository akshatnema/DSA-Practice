//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string longestString(vector<string> &words)
    {
        unordered_map<string, int> mp;
        string ans;
        for(int i=0;i<words.size(); i++){
            mp[words[i]]=1;
        }
        for(int i=0;i<words.size(); i++){
            int flag=0;
            for(int j=0;j<words[i].length();j++){
                string temp = words[i].substr(0, j+1);
                if(!mp[temp]){
                  flag=1;
                  break;
                }
            }
            if(!flag){
                if(!ans.length()){
                    ans=words[i];
                }else if(ans.length()<words[i].length()){
                    ans=words[i];
                }else if(ans.length()==words[i].length() && words[i]<ans){
                    ans=words[i];
                }else{}
            }
        }
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
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends