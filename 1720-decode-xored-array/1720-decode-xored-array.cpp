class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res = {first};
        for(int &it: encoded)
        {
            res.push_back(first ^= it);
        }
        return res;
    }
};