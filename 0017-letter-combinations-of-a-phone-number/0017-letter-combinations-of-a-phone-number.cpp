class Solution {
public:
    vector<string> ans;
    
    string dial(int key){
        unordered_map <int, string> mp;
        mp[0]=mp[1]="", mp[2]="abc", mp[3]="def", mp[4]="ghi", mp[5]="jkl", mp[6]="mno", mp[7]="pqrs", mp[8]="tuv", mp[9]="wxyz";
        
        return mp[key];
    }
    
    void rec(int i, string digits, string &temp){
        if(i==digits.length()){
            ans.push_back(temp);
            return ;
        }
        
        string t = dial(digits[i]-'0');
        for(int j=0;j<t.length();j++){
            temp.push_back(t[j]);
            rec(i+1, digits, temp);
            temp.pop_back();
        }
        return ;
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits == ""){
            return ans;
        }
        string temp;   
        rec(0, digits, temp);
        return ans;
    }
};