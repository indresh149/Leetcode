class SmallestInfiniteSet {
public:
    set<int>st;
    SmallestInfiniteSet() {
        st.clear();
        for(int i=1;i<=2000;i++)st.insert(i);
    }
    
    int popSmallest() {
        int mini= *st.begin();
        st.erase(mini);
        return mini;
        
    }
    
    void addBack(int num) {
        if(!st.count(num))st.insert(num);
        
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */