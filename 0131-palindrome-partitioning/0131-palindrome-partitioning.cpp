class Solution {
public:
    vector<vector<string>> ans;
    
    bool isPalindrome(string s) {
        string s1=s;
        reverse(s.begin(), s.end());
        return s1==s;
    }
    
    void rec(string s, vector<string> partitions, int i) {
        if(i>s.length()) return ;
        else if(i==s.length()){
            ans.push_back(partitions);
            return ;
        } else {}
        for(int index=i;index<s.length();index++) {
            string temp1=s.substr(i, index-i+1);
            
            if(isPalindrome(temp1)) {
                partitions.push_back(temp1);
                rec(s, partitions, index+1);
                partitions.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> partitions;
        string temp="";
        rec(s, partitions, 0);
        return ans;
    }
};