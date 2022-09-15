class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
       vector<int> ans;
    multiset<int> s;
	//insert all array elements in set
    for(auto x:changed)
       s.insert(x);
    
    while(!s.empty())
    {
        int ele = *s.begin();
        s.erase(s.find(ele));
		//find doubled element in the set if not found then return NULL and if found push the element in ans vector
        if(s.find(2*ele)==s.end())
            return {};
        s.erase(s.find(2*ele)); // erase the doubled element from the set so it cannot be accessed again
        ans.push_back(ele);
    }
    return ans;

    }
};