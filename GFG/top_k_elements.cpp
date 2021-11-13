// Question link - https://practice.geeksforgeeks.org/problems/top-k-frequent-elements-in-array/1

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
  static bool cnp(pair<int,int> a,pair<int,int> b)
  {
      if(a.first>b.first)
       return true;
      else if(a.first==b.first)
        return a.second>b.second;
      else 
       return false;
  }
  
    vector<int> topK(vector<int>& nums, int k) {
        unordered_map <int,int> mp;
         for(int i=0;i<nums.size();i++)
          mp[nums[i]]++;
         vector<pair<int,int>> vp;
         auto it=mp.begin();
         while(it!=mp.end())
         {
             vp.push_back(make_pair(it->second,it->first));
             it++;
         }
         sort(vp.begin(),vp.end(),cnp);
        vector <int> ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(vp[i].second);
        }
        return ans;
    }
};


// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends