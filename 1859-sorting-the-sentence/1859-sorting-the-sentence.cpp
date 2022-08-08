class Solution {
public:
    string sortSentence(string s) {
        map<int,string> mp;
        
        s.push_back(' ');
        string w  = "";
        for(auto it: s){
            if(it == ' '){
                string num = "";
                while(w.back() >= '0' && w.back() <= '9'){
                    num = (char)(w.back())+num;
                    w.pop_back();
                }
                int val = stoi(num);
                mp[val] = w;
                w= "";
            }
            else{
                w += (char)(it);
            }
        }
        string ans = "";
        for(auto i : mp){
            ans += i.second;
            ans += (char)(' ');
        }
        ans.pop_back();
        return ans;
    }
};