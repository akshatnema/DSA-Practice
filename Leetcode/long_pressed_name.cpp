// Question link - https://leetcode.com/problems/long-pressed-name/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
      if(name[0]!=typed[0])
          return false;
        for(int i=1,j=1;name[i]!='\0' || typed[j]!='\0';){
            if(name[i]==typed[j])
            {i++;j++;}
            else if(name[i]!=typed[j] && typed[j]==typed[j-1]){j++;}
            else return false;
        }
    return true;
    }
};