class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int res = 0;
        unordered_set<char> setJ(jewels.begin(), jewels.end());
        for (char s : stones)
            if (setJ.count(s)) res++;
        return res;
    }
};