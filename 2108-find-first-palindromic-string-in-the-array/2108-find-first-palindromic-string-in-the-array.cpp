class Solution {
public:
    bool isPallindrome(string s)
    {
        string p = s;
        reverse(p.begin(),p.end());
        if(p == s){
            return true;
        }
        return false;
    }
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            if(isPallindrome(words[i])){
                return words[i];
            }
        }
        return "";
    }
};