class Solution {
public:
    vector<vector<string>> ans;
    
    bool isPalindrome(string s) {
        string s1=s;
        reverse(s.begin(), s.end());
        return s1==s;
    }
    
    void rec(string s, string temp, vector<string> partitions, int i) {
        if(i>s.length()) return ;
        else if(i==s.length() && !temp.length()){
            ans.push_back(partitions);
            return ;
        } else {}
        string temp1 = temp + s[i];
        if(isPalindrome(temp1)) {
            partitions.push_back(temp1);
            rec(s, "", partitions, i+1);
            partitions.pop_back();
            rec(s, temp1, partitions, i+1);
        } else {
            rec(s, temp1, partitions, i+1);
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> partitions;
        string temp="";
        rec(s, temp, partitions, 0);
        return ans;
    }
};