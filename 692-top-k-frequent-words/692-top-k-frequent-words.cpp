class Solution {
public:
    bool static compare(pair<int,string> p1,pair<int,string> p2){
        if(p1.first == p2.first) return p1.second < p2.second;
        return p1.first > p2.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(auto word:words) mp[word]++;
        vector<pair<int,string>> vp;
        for(auto pr:mp){
            vp.push_back({pr.second,pr.first});
        }
        sort(vp.begin(),vp.end(),compare);
        vector<string> ans;
        for(int i=0;i<k;i++){
            ans.push_back(vp[i].second);
        }
        return ans;
    }
};