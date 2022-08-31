class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<int> st;
        for(auto it:sentence)
        {
            st.insert(it);
        }
        if(st.size() == 26)
        {
            return true;
        }
        else
            return false;
    }
};