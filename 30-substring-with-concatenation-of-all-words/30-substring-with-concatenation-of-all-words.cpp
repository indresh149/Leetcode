class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
       int len = words[0].length(), noOfWords = words.size();
        vector<int> result;
        map<string,int> wordMap;
        
        if(len * noOfWords > s.length()) 
            return result;
        
        for(string word : words)
            wordMap[word]++;
        
        for(int idx = 0; idx <= s.length() - (noOfWords*len);idx++){
            map<string,int> wordsUsedMap;
            
            for(int checkIdx = idx;checkIdx < idx + (noOfWords * len); checkIdx += len){
                string cur = s.substr(checkIdx, len);
                if(wordMap.find(cur) == wordMap.end())
                    break;
                
                wordsUsedMap[cur]++;
                
                if(wordsUsedMap[cur] > wordMap[cur])
                    break;
            }
            
            if(wordsUsedMap == wordMap)
                result.push_back(idx);
        }
        return result;
    }
};