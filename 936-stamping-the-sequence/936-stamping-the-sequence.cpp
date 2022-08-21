class Solution {

    //Fuction to check whether we can change our string to target string or not from ind index
    void replace(string & target,int ind,int s,int &count){
        for(int i=0;i<s;i++){
            if(target[ind+i]!='?'){
                target[ind+i]='?';
                count++;
            }
        }
    }
	
	//Fuction to change target string if we can replace
    bool canReplace(string &target,int&ind,string &stamp){
        for(int i=0;i<stamp.size();i++){
            if(target[ind+i]!='?'&&target[ind+i]!=stamp[i])return false;
        }
        return true;
    }
public:
    vector<int> movesToStamp(string stamp, string target) {
	    // variable to count how many characters we have changed in target string
        int count=0;
		
		//boolean array to check we have already changes from that index or not
        vector<bool>visited(target.size(),false);
		
		//ans array to return our answer
        vector<int>ans;
        
        while(count!=target.size()){
		    // bool variable to check whether we have changed something orr not in target string
            bool b=true;
            for(int i=0;i<=target.size()-stamp.size();i++){
			    // if at i not visted and we can replace
                if(!visited[i]&&canReplace(target,i,stamp)){
                    replace(target,i,stamp.size(),count);
					//changing b to false because we have changed target string
                    b=false;
					//marked true so that we dont check from same index
                    visited[i]=true;
					//pushed current index becuase we are changing
                    ans.push_back(i);
                }
				//checking if we have changed all the char in target array means we have done our task
                if(count==target.size())break;
            }
			// if we are not able to change anything we will return empty array
			//because we cannot make stamp to target
            if(b){
                vector<int>a;
                return a;
            }
        }
		//reversed the array because we changed from target 
        reverse(ans.begin(),ans.end());
        return ans;
    }
};