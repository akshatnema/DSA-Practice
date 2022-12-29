class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(!ransomNote.length() && magazine.length()) return false;
        unordered_map<char, int> mp;
        for(int i=0;i<magazine.length();i++){
            mp[magazine[i]]++;
        }
        for(int i=0;i<ransomNote.length();i++){
            auto it = mp.find(ransomNote[i]);
            if(it!=mp.end()){
                if(it->second){
                    it->second = it->second - 1;
                }else return false;
            }else return false;
        }
        return true;
    }
};