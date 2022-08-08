class Solution {
public:
    int balancedStringSplit(string s) {
        int lcounter = 0,rcounter = 0,counter = 0;
        
        for(int i=0;i<s.length();i++){
            if(s[i] == 'R') rcounter++;
            else lcounter++;
            if(rcounter == lcounter) counter++;
        }
        return counter;
    }
};