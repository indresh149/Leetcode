class Solution {
public:
    int partitionString(string s) {
        int ans = 1;
        set<char> st;
        
        for(int i=0;i<s.size();i++){
            if(st.find(s[i]) == st.end()){
                st.insert(s[i]);
            }
            else
            {
                ans++;
                st.clear();
                st.insert(s[i]);
            }
        }
        return ans;
    }
};