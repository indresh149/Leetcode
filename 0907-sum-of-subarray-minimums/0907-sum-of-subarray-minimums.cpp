class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long mod = 1e9+7, i, n = arr.size(), ans = 0, x;
        stack <int> st;
        vector <int> left(n), right(n);
        for (i=0;i<n;i++) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (st.empty())
            left[i] = i;
            else
            left[i] = i - st.top() - 1;
            st.push(i);
        }
        while (!st.empty())
        st.pop();
        for (i=n-1;i>=0;i--) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            if (st.empty())
            right[i] = n-i-1;
            else
            right[i] = st.top()-i-1;
            st.push(i);
        }
        for (i=0;i<n;i++) {
            x = ((left[i]*right[i])%mod + left[i] + right[i] + 1)%mod;
            ans = (ans + (x*arr[i])%mod)%mod;
        }
        return ans;
    }
};