class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int n= s.size();
        //if(n == 0) return 0;
        map<char,int> map; 
        int ans = 0;
        int i = 0,j = 0;
        while(j < n){
            map[s[j]]++;
            if(map.size() == (j - i + 1)){
                ans = max(ans , j-i+1);
                //j++;
            }
            else if(map.size() < (j - i + 1)){
               map[s[i]]--;
               if(map[s[i]] == 0){
                   map.erase(s[i]);
               }
               i++;
            }
            j++;
        }
        return ans; 
    }
};