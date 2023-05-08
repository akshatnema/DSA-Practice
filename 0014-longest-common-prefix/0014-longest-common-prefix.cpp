class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pre="";
        for(int i=0;i<strs[0].length();i++){
            int flag=0;
            for(int j=1;j<strs.size();j++){
                if(strs[j][i] != strs[0][i]) flag=1;
            }
            if(!flag){
                pre+=strs[0][i];
            }else break;
        }
        return pre;
    }
};