class Solution {
public:
    bool detectCapitalUse(string word) {
        bool first = false, second=false;
        if(word.length()>1){
            if(isupper(word[1])) second = true;
        }
        if(isupper(word[0])) first = true;
        for(int i=1;i<word.length();i++){
            if(isupper(word[i])){
                if(!first || !second) return false;
            }else{
                if(second) return false;
            }
        }
        return true;
    }
};