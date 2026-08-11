class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n,0);
        stack<pair<int,int>> st;
        st.push({temperatures[0],0});

        for (int i=1; i<n; i++){
            while (!st.empty() && temperatures[i] > st.top().first){
                res[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push({temperatures[i],i});
        }
        while (!st.empty()){
            res[st.top().second] = 0;
            st.pop();
        }
        return res;
    }
};
