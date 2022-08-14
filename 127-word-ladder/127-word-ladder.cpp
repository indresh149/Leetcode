class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> myset;
        bool isPresent = false; //Check if endWord is present in Dict
        //Insert all words from Dict in myset
        for(auto word: wordList)
        {
            if(endWord.compare(word) == 0){
                isPresent = true;
            }
            myset.insert(word);  //Insert word in Dict
        }
        if(isPresent == false)  //endWord is not present in Dict
            return 0;
        
        queue<string> q;
        q.push(beginWord);
        int depth = 0;
        
        while(!q.empty())
        {
            depth += 1;
            int lsize = q.size();   // No. of elemnts at a level
            
            while(lsize--)
            {
                string curr = q.front();
                q.pop();
                //Check for all possible 1 depth words
                for(int i=0;i<curr.length();++i)   //For each index
                {
                    string temp = curr;
                    for(char c = 'a';c <= 'z';++c)   // Try all possible chars
                    {
                        temp[i] = c;
                        if(curr.compare(temp) == 0){
                            continue;    // Skip the same word
                        }
                        if(temp.compare(endWord) == 0){
                            return depth+1;   // endWord found
                        }
                        if(myset.find(temp) != myset.end())
                        {
                            q.push(temp);
                            myset.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};