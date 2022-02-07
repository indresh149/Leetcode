class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string code[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> s;
        for(string each : words)
        {
            string Morsecoded = "";
            for(char ch : each)
            {
                Morsecoded += code[(ch - 'a')];
            }
            s.insert(Morsecoded);
        }
        return s.size();
    }
};