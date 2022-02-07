class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n=nums.size();
        int prefix[n],suffix[n];
        for(int i=0;i<n;i++){
            if(i==0)
            {
                prefix[i]=(nums[i]==0);
            }
            else{
                prefix[i]=prefix[i-1]+(nums[i]==0);
            }
        }
            for(int i=n-1;i>=0;i--){
                if(i==n-1){
                    suffix[i]=(nums[i]==1);
                }
                else
                {
                    suffix[i]=suffix[i+1]+(nums[i] == 1);
                }
            }
            vector<int> ans;
            int maxa=0;
            for(int i=0;i<=n;i++)
            {
                if(i==0) maxa=max(maxa,suffix[i]);
                else if(i==n) maxa=max(maxa,prefix[i-1]);
                else maxa=max(maxa,prefix[i-1]+suffix[i]);
            }
            for(int i=0;i<=n;i++)
            {
                int score;
                if(i==0) score = suffix[i];
                else if(i==n) score=prefix[i-1];
                else score = prefix[i-1]+suffix[i];
                if(score == maxa)
                    ans.push_back(i);
            }
        return ans;
        }
    
};