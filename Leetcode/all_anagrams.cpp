// Question link - https://leetcode.com/problems/find-all-anagrams-in-a-string/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
       vector<int> mp1(26,0);
       vector<int> mp2(26,0);
        vector <int> ans;
        if(p.length()>s.length())
            return ans;
       for(int i=0;i<p.length();i++){
           mp1[p[i]-'a']++;
       } 
       for(int i=0;i<p.length();i++){
           mp2[s[i]-'a']++;
       } 
       if(mp1==mp2){
           ans.push_back(0);
       }
       int i=0;
       for(int j=p.length();j<s.length();j++){
           mp2[s[i]-'a']--;
           // cout<<s[i]<<" "<<s[j]<<endl;
           i++;
           mp2[s[j]-'a']++;
           if(mp1==mp2){
               ans.push_back(i);
           }
       }
       return ans; 
    }
};