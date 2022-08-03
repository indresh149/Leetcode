class Solution {
public:
    string defangIPaddr(string address) {
        string ans = "";
        for(auto it:address){
            if(it == '.')
            {
                ans  += "[.]";
            }
            else
            {
                ans.push_back(it);
            }
        }
        return ans;
    }
};