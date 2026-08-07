class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 1;
        int best = 1;
        unordered_set<char> st;
        st.insert(s[0]);

        if (s.empty()) return 0;
        while(r < s.size()){
            while (st.count(s[r])){
                st.erase(s[l]);
                l++;
            }
            best = max(best, r-l+1);
            st.insert(s[r]);
            r++;
        }
        return best;
    }
};
