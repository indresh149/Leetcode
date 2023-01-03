class Solution {
public:
    string getHint(string secret, string guess) {
         int bulls = 0,cows = 0;
        
        vector<int> numbers(10);
        
        for(int i=0;i<secret.length();i++){
            int s = secret[i] - '0';
            int g = guess[i] - '0';
            if(s == g)
                bulls++;
            else{
                if(numbers[s] < 0) cows++;
                if(numbers[g] > 0) cows++;
                numbers[s]++;
                numbers[g]--;
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};